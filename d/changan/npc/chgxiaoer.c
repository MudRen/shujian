// Write By Yanyang@SJ 2001.9.27
// NPC: /d/changan/npc/chgxiaoer.c

inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("���С��", ({ "chaguan xiaoer", "xiaoer" ,"waiter"}) );
        set("gender", "����" );
        set("unique", 1);
        set("age", 18);
        set("long", "���ǳ����ǲ�����С������æ���Ȼ��졣\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("per", 18);

        set("chat_chance", 5);
        set("chat_msg", ({
"���С���������̧ͷ���˿��㡣\n",
"���С�����˲�ͷ�ϵĺ���\n",
"���С���������ʰ�ɾ���һ�����ӡ�\n",
        }) );
        
        set("vendor_goods", ({
        (["name":FOOD_D("peanut"),"number":20]),
        (["name":FOOD_D("chahu"),"number":20]),
}));

        setup();
        carry_object(ARMOR_D("cloth.c"))->wear();
}


void init()
{        
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
