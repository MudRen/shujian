// laozhe.c ҩ����ͷ

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����", ({ "lao zhe", "lao", "zhe" }));
        set("str", 20);
        set("gender", "����");
        set("age", 68);
        set("long", "����һ������ҽ����ɫ���󣬰׷���ѩ��\n");
        set("combat_exp", 68250+random(40000));
        set("attitude", "friendly");
	set("inquiry", ([
                "������" : "����ͷ�������Ǻ��ټ���\n",
                "name" : "��ͷ�����ռ͵ģ�������Ͳ���֪���˰ɡ�\n",
                "here" : "�����Ǹ��ۿڣ����д����˺ܶࡣ\n",
	]));
        set("vendor_goods", ({
		(["name":MEDICINE_D("jinchuang"),"number":25]),
		(["name":MEDICINE_D("yangjing"),"number": 10]),
		(["name":MEDICINE_D("baicao"),"number": 2]),

        }));
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
