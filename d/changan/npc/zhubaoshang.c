//  zhu.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�鱦��", ({ "zhubao shang", "shang", "laoban" }));
        set("shen_type", 1);

        set("gender", "����");
        set("age", 44);
        set("long", "��λ�ϰ���Ȼ����Ǯ�����ϴ����˽��ָ��\n");
        set_skill("unarmed", 24);
        set_skill("dodge", 21);
        set_temp("apply/damage", 18);

        set("combat_exp", 7000);
        set("attitude", "friendly");
        set("vendor_goods", ({
           (["name":BINGQI_D("yuxiao"),"number":5]),
           (["name":ARMOR_D("necklace"),"number":25]),
           (["name":ARMOR_D("goldring"),"number":25])
        }));
        
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("gold",5);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}