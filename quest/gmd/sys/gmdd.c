#define FBNPC   "/quest/gmd/npc/office"
#include <localtime.h>
#include <ansi.h>
inherit F_DBASE;

void create()
{
seteuid(ROOT_UID);
        set("channel_id", "�������Ƴ���");

        CHANNEL_D->do_channel( this_object(), "sys", "����ϵͳ�Ѿ�������\n"); 
set ("name","�������Ƴ���");
remove_call_out("check_time");
        call_out("check_time",5);
}
void check_time()
{
string ts = ctime(time());
	ts = ts[0..2];

if(ctime(time())[10..15] == " 20:00"){
      FBNPC->move("/d/city/wumiao");
CHANNEL_D->do_channel(present("kongxing dashi", load_object("/d/city/wumiao")),"chat", HBBLU+HIW"ħ��������ԭ���ұ��������Ӳ����������ɵ���������Զ����������ħȥҲ��\n"NOR);
	}
if(ctime(time())[10..15]==" 22:00"){
CHANNEL_D->do_channel( present("kongxing dashi", load_object("/d/city/wumiao")), "chat",HBBLU+HIW"����Զ��֮������ͣ�£�������������������ս��\n"NOR); 
destruct(present("kongxing dashi"));

	}
}
