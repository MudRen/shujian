inherit NPC;

inherit F_VENDOR;

void create()
{
	set_name("ҩʦ", ({ "yao shi", "yao", "shi"}));
        set("long", "����һλ����ḻ��ҩʦ���κ�ҩ��һ���������Ͽ��Ա�ʶ���Ǻγɷ������ġ�\n");
        set("gender", "����");
        set("age", 50);
        set("str", 20);
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("shen_type", 1);        
        set("combat_exp", 30000+random(2000));
        set("attitude", "friendly");
        set("vendor_goods", ({
           (["name": MEDICINE_D("xiaojindan"),"number":15]),
           (["name": MEDICINE_D("jindan"),"number":15]),
           (["name": MEDICINE_D("yangjing"),"number":12])
        }));

        setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
