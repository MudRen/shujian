// Room: /d/emei/zuantianpo2.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY "������" NOR);
        set("long", @LONG
����ʯ��ϴ���֮�䣬��·������ʯջ���ݣ�ֱ�����죬ʯ�Ŵ�һǧ����
�༶�����ڶ���ɽ���Ͽ���������µ����������ϣ�ǰ������ӣ�һ����졣
���·�С������졹����ζ���Ҳ��˶��С������¡������������¶��㵽
ϴ��أ����¿ɴ�����ʯ��
LONG
        );
        set("outdoors", "��üɽ");
        set("exits", ([ 
          	"eastdown" : __DIR__"zuantianpo",
          	"westup" : __DIR__"xixiangchi",
	]));
	
	set("lingwu", ([
		"skill" : "dodge",
		"low_limit" : 100,
		"up_limit" : 200,
		"lw_msg": CYN"$N���������Ͻ�ϴ��أ���������ʯ���¶�·�գ����ܿ���һ�����˵��Ṧ��\n"+
			  "��������Ĭ����$s��������ʼ����$b�������ѧ���⡣\n"NOR,
	]));
        set("no_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
 	if (dir == "westup" && (int)me->query_skill("dodge", 1) < 101 ) {
      		me->improve_skill("dodge",(int)me->query("dex"));
      		me->receive_damage("jingli",  (int)me->query("dex"));
      		return 1; 
      	}     
      	return ::valid_leave(me, dir);
} 
