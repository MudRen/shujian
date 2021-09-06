#define FBNPC   "/quest/gmd/npc/office"
#include <localtime.h>
#include <ansi.h>
inherit F_DBASE;

void create()
{
seteuid(ROOT_UID);
        set("channel_id", "副本控制程序");

        CHANNEL_D->do_channel( this_object(), "sys", "副本系统已经启动。\n"); 
set ("name","副本控制程序");
remove_call_out("check_time");
        call_out("check_time",5);
}
void check_time()
{
string ts = ctime(time());
	ts = ts[0..2];

if(ctime(time())[10..15] == " 20:00"){
      FBNPC->move("/d/city/wumiao");
CHANNEL_D->do_channel(present("kongxing dashi", load_object("/d/city/wumiao")),"chat", HBBLU+HIW"魔教觊觎中原，我辈岂能坐视不理，六大门派弟子且随我远征光明顶炼魔去也！\n"NOR);
	}
if(ctime(time())[10..15]==" 22:00"){
CHANNEL_D->do_channel( present("kongxing dashi", load_object("/d/city/wumiao")), "chat",HBBLU+HIW"今日远征之事暂且停下，你我养精蓄锐，明日再战！\n"NOR); 
destruct(present("kongxing dashi"));

	}
}
