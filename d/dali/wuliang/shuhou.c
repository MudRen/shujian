// shuhou.c
// bbb 1997/06/11
// Modify By River 98/12
// Modify by tangfeng 2004
inherit ROOM;
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#include <ansi.h>
void create()
{
	set("short", "���Ժ�");
	set("long", @LONG
�����ͺͺ��һ��Ƭʯ�ڣ���������������ʯ��ƽ���쳣����Ȼһ��ͭ����
ֻ�ǱȺ�����ɽ��С����࣬��ϸ����ʯ�ڣ�ƽ���⻬���������졣
LONG
	);
        set("exits", ([
		"out" : __DIR__"shulin1",
	]));
        set("outdoors", "����");
	setup();
}

void init()
{
	  object me;
    me = this_player();
	  if (me->query(QUESTDIR1+"start") 
	     && !me->query(QUESTDIR1+"wuliangover")
	     && me->query_temp(QUESTDIR1+"jianying") 
	     && !me->query_temp(QUESTDIR1+"see_duanyu1"))
	  {
      "/cmds/std/look.c"->look_room(this_player(), this_object());
      tell_object(me,HIY"\n���۹�˳�ź���һ·��չ��ȥ��ͻȻ֮��ȫ��һ��ֻ����������Ϻ�Ȼ�и���Ӱ���㶨�˶�������ȥ������Ӱ�����Ŀ��������\n"
                          "��һ��֮�£��㼴ʡ�򣺡������Լ���Ӱ�ӣ���������ϣ�������Ӱ������ϣ�����ң���ʱ���޻��ɡ���΢һ��˼��ֻ�����Ի���\n"
                          "������������ʮ��ġ������Ӱ��֮�գ�����˿������֮����������ȷ����վ������ʹ������Ӱӳ����ڡ�������һ��һŮ��������\n"
                          "�еĲ�֪�����˻������ˣ�ֻʣ��һ��Ů�ģ��������Ĺ��м�į�µ�������������Ҳ�����ˡ���һ�������ʧ�£������Ĺȣ�������\n"
                          "��������������Ȼ�����������������������ǰ�Ŀ�ϲ�Լ���Ӱ���٣���������֮�ʣ��㼴�����㵸��ȭ����ߣ����룺�������\n"
                          "���¡�˫��������ʱ�����¶�����������Ϻ��֡���Ӱ�����϶�������������ʾ�����书�����ǽ������ס��书������ѧ��ȥ��ƴ��\n"
                          "���У���֮��������������������Խ��Խ��Ȥ���̲�ס������Ц��\n"NOR);
    }
    add_action("do_down", "tear");
    add_action("do_down", "si");
}

int do_down(string arg)
{
	object me = this_player();
        if (!arg || arg!="teng") return 0;
        message_vision("$N��ʯ���ϵ�����˺�øɸɾ�����������档\n" , me);
        me->move(__DIR__"shibi");
        return 1; 
}
