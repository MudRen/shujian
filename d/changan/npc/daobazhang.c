// Write By Yanyang@SJ 2001.9.27
// NPC : /d/changan/npc/daobazhang.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("������", ({ "daoba zhang", "daoba", "zhang"}) );
        set("gender", "����" );
        set("age", 35);
        set("per", 14);
        set("unique", 1);
        set("long","������һ������ĵ��̣���Ҷ����������š�\n");
        set("combat_exp", 10000);
        set("vendor_goods", ({
                (["name":BINGQI_D("sword/sword"),"number":10]),
                (["name":BINGQI_D("blade/blade"),"number":10]),
                (["name":BINGQI_D("hammer/chui"),"number":10]),
                (["name":BINGQI_D("club/gun"),"number":10]),
                (["name":BINGQI_D("staff/gangzhang"),"number":10]),
                (["name":BINGQI_D("whip/whip"),"number":10]),
                (["name":BINGQI_D("hook"),"number":10]),
                (["name":BINGQI_D("stick"),"number":10]),
                (["name":BINGQI_D("axe"),"number":10]),
        }));
        set("chat_chance", 5);
        set("chat_msg", ({
                "�����������̾�˿�����\n",
                "�����ſ��˿��Լ�����������Ĳ�֪��˵Щʲô��\n",
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}