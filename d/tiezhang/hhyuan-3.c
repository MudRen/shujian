//hhyuan-3.c ��ɽ
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", YEL"��ɽ"NOR);
	set("long", @LONG
����ǰ������һ���޴�ļ�ɽ��һ��Ƭ��Ҳ�Ƶ����ٴӼ�ɽ��к��������
ע��ǰ���һ��������У�����������������кˮͨ����������ˮȴ�������硣
���ư�Ϊ�������԰��Ҳ��֪�����˶����������������ٲ��ĺ����ƺ���Լ��
��С�š�
LONG	);
	set("exits", ([ 
"east" : __DIR__"hhyuan-1",
]));

	set("no_clean_up", 0);
        set("outdoors", "tiezhang");

	set("coor/x",-340);
  set("coor/y",-230);
   set("coor/z",10);
   setup();
}

void init()
{
         add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if (arg !="�ٲ�") 
            return notify_fail("��Ҫ���Ķ�������\n");
        {
            write("���������ٲ���Ծȥ��\n");
                message("vision",me->name() + "����һ��ͻȻ�����ˡ�\n",environment(me), ({me}));
            me->move(__DIR__"mishi");
            message("vision",me->name() + "���˹�����\n", environment(me), ({me}));
        }
        return 1;
}
