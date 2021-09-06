// Room: cuigu3.c
// By River@SJ
// Update by Lklv , nip river

#include <ansi.h>
inherit ROOM;
string look_zi();
void create()
{
        set("short", HIG"���"NOR);
        set("long", @LONG
����ǰ�Ǹ����Ž��صĴ�ȣ��컨������������ӳ������̤�ŵ�������ϸ
�ݣ������ŵ��������Ļ��㣬���ݼ�أ��ʹ���֦�����ɵ��Ŀ����������ɽ
���Ͽ���һ��С��(zi)������̫Զ���㿴�����С�
LONG    );

        set("exits", ([
                "north" : __DIR__"cuigu",
        ]));
        set("item_desc", ([
           "zi" : (: look_zi :)
        ]));

        set("outdoors", "���ش��");
        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_mai",({"mai","cang"}));
        add_action("do_wa", ({"qu", "jue"}));
}

string look_zi()
{
	object me=this_player();
	if (me->query("jiuyang/mai"))
		return HIW"\t\t"+me->name()+"�񾭴�\n"NOR;
	else
		return "ʱ���Զ�����긯ʴ�����Ѿ��������������д���ּ��ˡ�\n";
}

int do_mai(string arg)
{
	object me=this_player();
	object ob;
	if(!me->query("jiuyang/baiyuan")) return 0;
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if( arg =="book" || arg =="jiuyang zhenjing"){
		if( !objectp(ob = present("jiuyang zhenjing", me)))
			return notify_fail("�����Ϻ���û�а�����ô�񰡣�\n");
		message_vision(HIW"\n$N��ɽ��������˸���������Ķ��ף����ľ�����澭���ڶ��ڣ�������������\n"+
                          "Ȼ��ʰ��һ���ʯ����ɽ���ϻ��¼������֣�"+me->name()+"�񾭴���\n\n"NOR,me);
		if(!me->query("jiuyang/mai"))
			me->set("jiuyang/mai", 1);
		me->delete_temp("get_9yjing");
		destruct(ob);
		return 1;
        }
	return notify_fail("��Ҫ��ʲô��������\n");
}

int do_wa(string arg)
{
	object me = this_player();
	object ob;
	if(!me->query("jiuyang/mai")) return 0;
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if( arg =="book" || arg =="jiuyang zhenjing"){
		if(me->query_temp("get_9yjing"))
			return notify_fail("����һ��������ɽ���еľ����澭��Ȼ��������֪��˭�����ˣ���\n");
		ob = unew(BOOK_D("jiuyang"));
		if ( !clonep(ob))
			return notify_fail("����һ��������ɽ���еľ����澭��Ȼ��������֪��˭�����ˣ�\n");
		message_vision(HIY"\n$N�������ڿ�������������ľ����澭ȡ�˳�����\n\n"NOR,me);
		ob->set_temp("jiuyang",me->query("id"));
		me->set_temp("get_9yjing", 1);
		ob->move(me);
		return 1;
        }
        return notify_fail("��Ҫ�ھ�ʲô��\n");
}
