#include <ansi.h>
inherit NPC;
string ask_gift();
void create()
{
        set_name("�����", ({"robot darken", "darken", "robot"}) );
        set("long", "�����������������������õĻ����ˡ�\n");
        set("gender", "����" );
        set("title", "������");
        set("age", 24);
        set("attitude", "peaceful");
        set("str",1);
        set("int",99);
        set("con",99);
        set("dex",99);
        set("per",99);
        set("max_qi", 1000000);
        set("max_jing", 1000000);
        set("neili", 10000000);
        set("max_neili", 1000000);
        set("eff_jingli",1000000);
        set("jiali", 0);
        set("combat_exp", 30000000);
        set("unique", 1);

        set("shen_type", 1);
        set("class", "fighter");

        set("inquiry", ([
                "����": (: ask_gift :),
        ]) );

        setup();
}

string ask_gift()
{
        object ob = this_player();
        object gift;
        if (!ob->query("biwu_winner"))
           return RANK_D->query_respect(ob)+"��ʲô���֣�\n";
        if (present("biwu gift", ob))
           return RANK_D->query_respect(ob)+"���ϲ�������ô��\n";

        gift = new("/d/huanghe/obj/"+ob->query("id"));
        gift->move(ob);
        message_vision("$N�õ���"+gift->query("name")+"��\n", ob);
        return "С���պð�����С�Ķ��������Ұɡ�\n";
}

