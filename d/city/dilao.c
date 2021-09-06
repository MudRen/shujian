// Room: /d/city/dilao.c
// Modify by Looklove@sj 2000/10/16

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������ź�Ժ�ĵ��Σ��Ĵ��м���������Ѳ�ߣ�����ɭ�ϡ���ʱ������
������۸����������������ߺ�������������֡�ż���м��������ڿ��ص�Ѻ
���£����������Ѻ�����ߵ������Ͽ���һ��С����(window)��Ϊ�˷���̽
��İ��գ����Դ�������ڴ���(pass)Щ�ԵĶ�����ȥ��
LONG
        );

        set("item_desc", ([
                "men" : "����һ�ȼ�������š�\n",
        ]));
        set("exits", ([
                "southup" : __DIR__"fyhouyuan",
        ]));

        set("objects", ([
                __DIR__"npc/yayi" : 1,
        ]));
   setup();
}
void init()
{
        add_action("do_visit", "look");
        add_action("do_pass", "pass");
add_action("do_unlock", "unlock");
add_action("do_unlock", "kai");
}

int do_pass(string arg)
{
        object ob;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");

        if (ob->query_weight() > 5000)
                return notify_fail(ob->query("name")+"̫���ˣ����ܴӴ���������ȥ��\n");

        if (ob->query("no_drop") || ob->query("id") == "man tou" || ob->query("id") == "hulu" || ob->is_container() || ob->query("hsf"))
                return notify_fail("��������Ų���ȥ��\n");

        message_vision("$N��һ"+ob->query("unit")+"$n�Ӵ������˽�ȥ��\n", this_player(), ob);
        ob->move("/d/city/laofang");
        message("vision", this_player()->name()+"�Ӵ���������һ"
                +ob->query("unit")+ob->query("name")+"��\n",environment(ob), ob);
        return 1;
}
int do_visit(string arg)
{
        object env, me = this_player(); 

        if (arg != "window") return 0;

        if(!( env = find_object("/d/city/laofang")) )
                env = load_object("/d/city/laofang");

        message_vision("$Nſ�ڴ�̨��������ȥ��\n", me);
        tell_room(env, "��е���һ˫�۾��ڴ�������㡣\n");
        return COMMAND_DIR"std/look"->look_room(me, env);
}
int do_unlock(string arg)
{
        object ob,me;
        me = this_player();
        
        if (query("exits/west"))
                return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
        if (!arg || (arg != "men" && arg != "west"))
                return notify_fail("��Ҫ��ʲô��\n");
        if (!(ob = present("dilao yaoshi", me)))
                return notify_fail("��û��Կ�ף��򲻿�������š�\n");
        
        set("exits/west", __DIR__"laofang");
        me->set("succor",1);
        message_vision("$N�ó�һ��Կ�״������ţ�����Կ��ȴ���������ò������ˡ�\n", me);
        destruct(ob);
        return 1;
}
int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("kan shou", environment(me))) && 
                dir == "west")
                return notify_fail("������ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}

