// fenduo2.c ؤ����·ֶ�(���ݷ�ĹĹ��)
// Lklv modify 2001.9.27

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","Ĺ��");
	set("long", @LONG
����һ���ܴ��Ĺ�ң��������Ų����ˡ�ǽ�Ϲ����˻�棬�յù������ġ�
ԭ�������ؤ��Ĵ��·ֶ棬һȺ��ؤΧ�ŵ�ͼ���ƺ����ڼ��ҵ�������ʲô��
ǽ�Ǵ�����һ�ڿݾ�(well)��
LONG
	);

	set("valid_startroom",1);
	set("item_desc",([
		"well" : "��������ɵģ���֪ͨ�����\n",
	]));

	set("exits", ([
		"north" : __DIR__"mszoulang",
	]));

	set("objects",([
		CLASS_D("gaibang/xi") : 1,
		CLASS_D("gaibang/ma") : 1,
		CLASS_D("gaibang/jydizi") : 1,
	]));
	setup();
	call_other("/clone/board/gb_board2", "???");
}

void init()
{
        object me = this_player();

        if ( me->query("title") == "ؤ����·ֶ��������"){
		me->set("title","ؤ����·ֶ�һ������");
	}
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if( arg=="well" ){
		if (me->is_busy())
			return notify_fail("����æ���ء�\n");
                message("vision", me->name()+"���������һ������һ���ۣ�������������ȥ��\n", environment(me), ({me}));
                me->move(__DIR__"shangang");
                message("vision", me->name() + "�ӷ�Ĺ�����˳�����\n",environment(me), ({me}) );
                return 1;
        }
}
