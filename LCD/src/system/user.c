//#include "system.h"
//#include "user.h"
//
//static int curPage = 0;
//UINT32 u_bitmap;
//
//#define   USRS_PERPAGE   (10) 
//
//static int validUser[MAX_USER];
//static UINT16 userIDs[USRS_PERPAGE] = {     
//     ID_UMAN_Code1
//    ,ID_UMAN_Code2
//    ,ID_UMAN_Code3
//    ,ID_UMAN_Code4
//    ,ID_UMAN_Code5
//    ,ID_UMAN_Code6
//    ,ID_UMAN_Code7
//    ,ID_UMAN_Code8
//    ,ID_UMAN_Code9
//    ,ID_UMAN_Code10
//};
//
//static void get_all_users()
//{
//    int i = 0;
//    int j = 0;
//    unsigned data;
//    
//    for (i = 0; i < MAX_USER; i++ ){
//        if ( u_bitmap&(1<<i) ){
//            for ( j = 0; j < ALIGN_USER; j++ ){
//                data = readSEE(EE_USR_CODE_BASE + (ALIGN_USER*i + j)*INT_BYTES);
//                g_oprtIds[i][j*INT_BYTES ] = data&0xff;
//                g_oprtIds[i][j*INT_BYTES + 1] = (data>>8)&0xff;
//                g_oprtIds[i][j*INT_BYTES + 2] = (data>>16)&0xff;
//                g_oprtIds[i][j*INT_BYTES + 3] = (data>>24)&0xff;
//            }
//        }
//    }
// }
//
//void initUserMan()
//{
//    u_bitmap = readSEE( EE_USR_CODE_BITMAP );
//    //u_bitmap = 0;
//    memset( g_oprtIds, 0, sizeof( g_oprtIds ) );
//    
//    get_all_users();
//}
//
//BOOL saveUser( const char c[] )
//{
//    int i = 0;
//    int j = 0;
//    unsigned data;
//    int len = strlen( c );
//    if ( !len )
//        return FALSE;
//    
//    for ( i = 0; i < MAX_USER; i++ ){
//        if ( !strcmp( g_oprtIds[i], c ) )
//            return FALSE;
//    }
//    
//    len = (len < CODE_LEN) ? len : CODE_LEN;
//    
//    for ( i = 0; i < MAX_USER; i++ ){
//        if ( !(u_bitmap&(1 << i)) ){
//            u_bitmap |= (1 << i);
////            memset( g_oprtIds[i], 0, CODE_LEN );
//            memcpy( g_oprtIds[i], c, len );
//            
//            for ( j = 0; j < ALIGN_USER; j++ ){
//                data = g_oprtIds[i][j*INT_BYTES];
//                data |= g_oprtIds[i][j*INT_BYTES+1] <<8;
//                data |= g_oprtIds[i][j*INT_BYTES+2] <<16;
//                data |= g_oprtIds[i][j*INT_BYTES+3] <<24;
//                
//                writeSEE( EE_USR_CODE_BASE + (ALIGN_USER*i + j)*INT_BYTES,  data);
//            }
//            
//            writeSEE( EE_USR_CODE_BITMAP, u_bitmap );
//            
//            showNextPageUsers();
//            
//            return TRUE;
//        }
//    }
//    
//    return FALSE;
//}
//
//static BOOL delUser( int index )
//{
//    if ( index < MAX_USER && index >= 0 )
//    {
//        memset( g_oprtIds[index], 0, CODE_LEN );
//        u_bitmap &= ~(1 << index);
//        writeSEE( EE_USR_CODE_BITMAP, u_bitmap );
//        
//        showUserCodes();
//        
//        return TRUE;
//    }
//    
//    return FALSE;
//}
//
//BOOL rmUser( const char c[] )
//{
//    int i = 0;
//    
//    for ( ; i < MAX_USER; i++ ){
//        if ( !strcmp( g_oprtIds[i], c ) ){
//            return delUser( i );            
//        }
//    }
//    
//    return FALSE;
//}
//
//char* getUser( int index )
//{
//    if ( u_bitmap&(1 << index) ){
//        return g_oprtIds[index];
//    }
//    else
//        return 0;
//}
//
//void showLastPageUsers()
//{
//    if ( curPage == 0 )
//        return;
//    
//    curPage--;
//    
//    showUserCodes();
//}
//
//void showNextPageUsers()
//{
//    if ( curPage >= 3 )
//        return;
//    
//    curPage++;
//    
//    showUserCodes();    
//}
//
//void showUserCodes()
//{
//    int i = 0;
//    int cnt = 0;
//    
//    while( i < MAX_USER ){
//        if ( u_bitmap&(1 << i) ) {
//            validUser[cnt] = i;
//            cnt++;            
//        }
//        i++;
//    }
//    
//    UINT16 maxPage = cnt / 10;
//    if ( cnt%10 )
//        maxPage++;
//    
//    if  ( 0 == maxPage )
//        return;
//    
//    if ( curPage + 1 > maxPage )
//        curPage = maxPage - 1;
//    
//    UINT16 u_i = 0;
//    for ( i = 0; i < 10; i++ ){
//        u_i = validUser[curPage*10 + i];
//        
//        if ( cnt > curPage*10 + i )            
//            Ui_Show_Str_Var( userIDs[i], g_oprtIds[u_i] );
//        else
//            Ui_Show_Str_Var( userIDs[i], "___            " );
//    }  
//}