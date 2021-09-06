// tomb.c ���ݷ�Ĺ
// Lklv modify 2001.9.27

#include <ansi.h>
inherit ROOM;

string look_shibei();
int do_pull(string arg);
void close_door();

void create()
{
	set("short","��Ĺ");
	set("long", @LONG
����һ�����ڸ�����ߴ���һ����أ����ϲ��˼����㣬����ȼ�š�����
���˾������⡣��������һ����ʯ��(shibei)���Ա߻���һ������(huan)����
���ܴ󣬳���������Զ���������󹷷�������ʲôҲ��������
LONG
	);
	set("outdoors","����");

	set("item_desc",([
		"shibei" : (: look_shibei :),
		"huan" : "����һ������������ȥʮ�ֹ⻬��\n",
	]));

	set("exits",([
		"south" : __DIR__"shangang"
	]));
	setup();
}

void init()
{
	add_action("do_pull", "pull");
}

string look_shibei()
{
	return
	"\n"
	"   ������������������������������   \n"
	"   ������                  ������   \n"
	"   ������     ������²     ������   \n"
	"   ������     ���Һ�ɽ     ������   \n"
	"   ������                  ������   \n"
        "   ������������������������������   \n";
}

int do_pull(string arg)
{
        object room;

	if( !arg || arg!="huan" ) return 0;
	message("vision","Ĺ����Ȼ������������������һ�໺���ƿ���"
	                "����¶��һ���ڶ�������ڡ�\n", this_object() );
	set("exits/down", __DIR__"fenduo2");
	if( room = load_object(__DIR__"fenduo2") ) {
 		 room->set("exits/up", __FILE__);
		 message("vision", "ͷ���ϵ�Ĺ����Ȼ����������������¶��һ���������Ķ��ڡ�\n",room );
	}
	remove_call_out("close_door");
	call_out("close_door", 3);
        return 1;
}

void close_door()
{
	object room;

        if( !query("exits/down") ) return;
        message("vision","Ĺ����Ȼ�����������������������ƻ�ԭ����"
                "�����µĶ��ڸ�ס�ˡ�\n", this_object() );
        if( room = load_object(__DIR__"fenduo2") ) {
                room->delete("exits/up");
                message("vision", "ͷ���ϵ�Ĺ����Ȼ����������������"
                        "ǽ�ϵ�ʯ���ֻ��������˻�ȥ��������ʧ�ˡ�\n",
			room );
        }
        delete("exits/down");
}