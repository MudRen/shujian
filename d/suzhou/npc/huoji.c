// huoji. ҩ�̻��

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
        set("str", 20);
        set("gender", "����");
        set("age", 18);
        set("long", "����һλ����������æ�Ļ�ơ�\n");
        set("combat_exp", 250);
        set("attitude", "friendly");
        set("vendor_goods", ({
           (["name":__DIR__"obj/lianzi-wan","number":10]),
           (["name":__DIR__"obj/zhengqi-dan","number":10])

          }));

        setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

