// ��̬װ��aotuload�����ļ�  by hongba
inherit F_SAVE;
#include <ansi.h>
#include <mudlib.h>
#include <net/socket.h>
#include <socket_err.h>
#include <database.h>

void check_user_object(object me)
{
mapping ob_equ;
mixed worker_array;
object * inv;
int i;
if( !mapp(me->query("ob_equ")) ) return;
worker_array = values(me->query("ob_equ"));
for(i=0;i<sizeof(worker_array);i++) {
                if ( mapp(ob_equ = worker_array[i]) && stringp(ob_equ["save_id"]) )

return ;  // ��֪���������ôд��ֻ��д��return.... �ڴ�jpeiͬ־
        }

}

