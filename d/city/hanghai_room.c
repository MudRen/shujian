#include <ansi.h>

int errs( string msg )
{
     if( !msg ) return 0;
    write( msg );
    return 1;
}

inherit ROOM;

#define MST		"/clone/npc/hanghai_master"		// ��γ�ǣ���Ϸָ����֧��


void create()
{
	set("short", HIC"���Ϻ�̽������ֻ"NOR);
	set("long", @LONG
����һ���Ϻ�̽���Ĵ�ֻ����������֪�ж���Ӣ�ۺ��ܳ��Զ��������������
����ȫ������ľ���ɡ�һ���ŵķ��˴Ӵ󺣴�����ʹ֮��ס�ص�������ͷ��һ����
�ɵ�����(sign)д�ż����֡�
LONG
        );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("valid_startroom", 1); // �������ֱ�Ϊ�������߷��� �� ��ʼ����
        set("item_desc", ([
                        "sign":
                    "������������������������������"+HIG"�Ϻ�̽����֪"NOR+"��������������������������������\n"
                        "�� һ���ڿ���ʹ��(game start)����ʼ̽��                                 �� \n"
                        "�� ������̽��;�п���ʹ��(game over)������̽��                          �� \n"
                        "�� ��������(help job tanbao)����ѯ����˵����                            �� \n"
                        "�������������������������������������������������������������������������� \n\n"
                        ]) );
	set("exits", ([
	    "out":  "/d/city/guangchang",
	]));

	setup();
}

void init()
{
	add_action("do_game", "game");
}

int do_game(string arg)
{
	object me = this_player(), mst_obj;

	if( !arg || arg != "start" )
		return 0;

// "game over" �Ȳ������� MST ������С�


	if( me->query_temp("hanghai_gameing") )
		return errs("����������Ϸ�У�\n");

	if( file_size( MST + ".c" ) < 1 )
		return errs("����Ϸ��ͣ���ţ�\n");

	write("\n========= ���Ժ�����ִ�в������� ==========\n\n");

	mst_obj = new( MST );

	mst_obj->new_game(me);
	mst_obj->move(me);

	return 1;
}



int valid_leave(object me, string dir)
{
	if( me->query_temp("hanghai_gameing") )
		return notify_fail("�㲻��������Ϸ�𣿣������뿪�����Ҫ�뿪�Ƚ�����Ϸ(game over)�����뿪��\n");

	return ::valid_leave(me, dir);
}
