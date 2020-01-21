#include <Edi/OutlineManager.h>
#include <Edi/EdiBuffer.h>
#include <Edi/includes.h>

#include <FL/Fl_Browser.H>

////////////   TEST TEST TEST TEST   //////////////////////

void checkBitwise( char c ) {
    fprintf( stderr, "%#x & 0xc0 = %#x\n", c, (c & 0xc0) );
}

unsigned int u8strlen( const char* s ) {
    int len = 0;
    while ( *s ) len += ( *s++ & 0xc0 ) != 0x80;

    return len;
}

void showEachByte( const char* s ) {
    fprintf( stderr, "\n--------dumping %s----------\n", s );
    fprintf( stderr, "u8strlen(): %d\n", u8strlen( s ) );

    for( int i = 0, max = strlen( s ); i < max; i++, s++ ) {
        fprintf( stderr, "s at %d: %#x\n", i, (char)*s );
    }


    fprintf( stderr, "\n--------dump terminated-------\n" );
}

void test_string( const char* cstr ) {
    fprintf( stderr, "sizeof( char ): %ld\n", sizeof( char ) );
    fprintf( stderr, "cstr: %s -- len: %d\n", cstr, (int)strlen( cstr ) );

    unsigned int len = u8strlen( cstr );
    fprintf( stderr, "u8strlen() = %d\n", len );

    const char* UML = "äöüß";
    if( !strcmp(cstr, UML ) ) {
        fprintf( stderr, "Input equals UML!\n" );
    } else { fprintf(stderr, "Input: %s, UML: %s\n", cstr, UML ); }

    std::string s( cstr );
    fprintf( stderr, "Länge von s: %d\n", (int)s.length() );

    showEachByte( cstr );
}

////////////   END  OF  TEST  SECTION  //////////////////////

void OutlineManager::setCodeBuffer( EdiBuffer* pBuf ) {
    _pBuf = pBuf;
    _pBuf->add_modify_callback( static_modified_cb, this );
    createOutline();
}

const char* OutlineManager::checkFunctionSignature( const char* cstr ) const {
    return NULL;
}

void OutlineManager::createOutline() const {
    const char* pCode = _pBuf->text();
    for( int pos = 0, maxpos = _pBuf->length(); 
         pos < maxpos; pos = _pBuf->line_end( pos ) + 1 )
    {
        char* pTxt = _pBuf->line_text( pos );
        const char* pSig = checkFunctionSignature( pTxt );
        cerr << pTxt << endl;
        free( pTxt );
    }

}

void OutlineManager::static_modified_cb( int pos, int nInserted, int nDeleted,
      int nRestyled, const char* deletedText,
      void* cbArg ) 
{
    OutlineManager* pMan = (OutlineManager*)cbArg;
    pMan->modified_cb( pos, nInserted, nDeleted, deletedText );
}

void OutlineManager::modified_cb( int pos, int nInserted, int nDeleted,
                                  const char* deletedText ) 
{

}
