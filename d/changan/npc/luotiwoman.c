// Write By Yanyang@SJ 2001.9.26
// NPC: /d/changan/npc/luotiwoman.c

inherit NPC;
void create()
{
        set_name("����Ů��", ({ "luoti nvzi","nvzi" }) );
        set("gender", "Ů��" );
        set("age", 26);
        set("per",30);
        set("no_quest", 1);
        set("long","����һλ����ϴ�������Ů�ˡ�\n");

        setup();
}

void init()
{
        add_action("do_look", "look");
}

int do_look(string arg)
{
	object me=this_player();
        if ( arg == "luoti nvzi" || arg == "nvzi") {
        command("say ��ʲô����û������");
        message_vision("����Ů�Ӻݺݵ���$Nһ�ۡ�\n\n",me);
        }
        return 0;
}
