// huoji. ҩ�̻��

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
        set("str", 20);
        set("gender", "����");
        set("age", 18);
        set("long", "����ƽ��ҽ������������æ�ġ�\n");
        set("combat_exp", 250);
        set("attitude", "friendly");
        set("vendor_goods", ({
        (["name":MEDICINE_D("jinchuang"),"number":25]),
        (["name":"/clone/medicine/m-book1","number":5]),
        (["name":"/clone/medicine/jingmai/jingmai-book1","number":1]),
        (["name":MEDICINE_D("yangjing"),"number": 20]),
        }));

        setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

