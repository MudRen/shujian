// /d/city/yuelaoting.c
// update by beyond
// add help by Lklv

#include <ansi.h>

inherit ROOM;
string jiehun_zn();

void create()
{
	set("short", HIG"����ͤ"NOR);
	set("long", @LONG
����������ͤ���Ǿٰ����ĳ�����ͤ�����ܵ�������������������Ҳ��
Щ����Ф�񻭣������в������������������ϣ�����Ҹ������ż���м���
���������ú�ʹ��˳�����ʮ�����ۡ��ܶ������˶�����������������������
���ǵĻ���ͤ�ߵ������Ϲ���һ����ľ��(mu pai)��
LONG
        );
        set("item_desc", ([
                "mu pai" : (: jiehun_zn() :),
        ]));
	set("exits", ([
		"west" : __DIR__"yueqidian",
		"north" : __DIR__"yltw",
        ]));
	set("objects",([
		NPC_D("yuelao") : 1,
                NPC_D("shuanger") : 1,
        ]));
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("incity",1);
	setup();
	call_other("/clone/board/yuelao_b", "???");
}

string jiehun_zn()
{
	object me = this_player();
	if (!me->query_temp("look_zn")){
	write("\n
		"HIM"���ָ��"NOR"
	���飺
	    �з�����ָ� qiu <Ů��Ӣ������>
	    Ů������ָ� marry <�з�Ӣ������>

	��飺
	    ��Ů˫����Ҫ��������ͤ��������Ҫ�Ҹ��������ڳ���
	    ����������ָ� zuomei <Ů��Ӣ������>
	    ��  ������ָ� jiehun <Ů��Ӣ������>

        �����Σ�
            ������ͤ�����η�ͷ����
            �з�����ָ� give tou 100 gold
            Ů������ָ� enter jiao
            Ȼ��Ů���������˽�����з�������ͷ���η��ǻ�̧�Ž��Ӹ����з���
            ��������ˣ��������У��з�����ָ� say here
		");
		me->set_temp("look_zn", 1);
		return "\n";
	}
	else
	write("\n
		"HIY"���ָ��"NOR"
	��飺
            �����е�˫����Ҫ�����ߣ�
	    ����һ���ڴ�����ָ� lihun <�Է�Ӣ������>

        ������
            �����е��κ�һ��������������û�����ߣ�
            ����һ�����Ե����������顣
            ָ��ͬ�ϡ�
		");
		me->delete_temp("look_zn");
		return "\n";
}
