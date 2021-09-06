// Room: /d/shaolin/shifang.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit ROOM;
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"
void create()
{
    set("short", BLU"ʯ��"NOR);
    set("long", 
"һ���޴���Ʒ��������Ƭɽ��֮�䣬�Ʒ����Ϸ�������������Ľ��֣�\n"
"\n\t\t\t��"HIY"���µ�һ��ɲ"NOR"��\n\n"+
"�ּ���Щ���䣬����ȥ�����Ϊ��Զ�ˡ�ǰ����һƫ�ܴ�Ĺ㳡��վ����ǰ��\n"+
"�������ͺ�һЩ�����ϵĺ�ʿ�������������µ�ɽ�ŵ�ʹ����ڹ㳡����\n"+
"һ�ࡣ\n"
    );

	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"shijie11",
	]));

	set("outdoors", "shaolin");
	setup();
}

void init()
{
	object me = this_player();
	
	if ( me->query("sl_job")){
		me->add("job_time/����", me->query("sl_job"));
		me->delete("sl_job");
	}
}
int valid_leave(object me, string dir)
{
  if(dir == "south" && me->query(QUESTDIR3+"bad") && me->query_temp(QUESTDIR5+"zhangxing") && !me->query_temp(QUESTDIR5+"zhenfa"))
  {
   tell_object(me,HIC"\n���Ҫ׼���뿪�����¡�ͻȻһ��һ��������Ӱ�ɱ���������Ȼ����������ɮ������һս��ؤ�����塣\n"NOR); 
   me->move("/d/shaolin/shifang_copy");
   log_file("quest/TLBB", sprintf("%s(%s)�����������һս��ʼ�����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
   return notify_fail(HIR"������һս��ʵ�������ˡ�\n"NOR);
  }
	return ::valid_leave(me, dir);
}
