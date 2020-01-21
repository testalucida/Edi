#ifndef OUTLINEMANAGER_H
#define OUTLINEMANAGER_H

class EdiBuffer;
class Fl_Browser;

class OutlineManager {
    public:
        OutlineManager( Fl_Browser* pOutline ) { 
            _pOutline = pOutline; 
        }
        void setCodeBuffer( EdiBuffer* );
        void createOutline() const;
        const char* checkFunctionSignature( const char* ) const;
        static void static_modified_cb( 
                        int pos, int nInserted, int nDeleted,
                        int nRestyled, const char* deletedText,
                        void* cbArg );
        void modified_cb( int pos, int nInserted, int nDeleted,
                          const char* deletedText );
    private:
        EdiBuffer* _pBuf;
        Fl_Browser* _pOutline;
};

#endif