// liuzz.c ����ׯ
// Lklv 2001.9.28 update for open ���Ƿֶ�

inherit NPC;

int action_1();

void create()
{
        set_name("����ׯ", ({"liu zhuzhuang", "liu" }));
        set("title", "ؤ����Ƿֶ��������");
        set("gb/bags", 5);
        set("gender", "����");
        set("age", 28);
        set("long", "����ؤ��������ӣ����Ƿֶ����°��ڡ�\n");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 25);

        set("qi", 800);
        set("max_qi", 800);
        set("jing", 600);
        set("max_jing", 600);
        set("eff_jingli", 750);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);

        set("combat_exp", 200000);

        set_skill("force", 80); // �����ڹ�
        set_skill("huntian-qigong", 80); // ��������
        set_skill("strike", 80); // ����ȭ��
        set_skill("dodge", 80); // ��������
        set_skill("xiaoyaoyou", 60); // ǧ������
        set_skill("parry", 80); // �����м�
        set_skill("lianhua-zhang", 80);

        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
	map_skill("strike", "lianhua-zhang");
	map_skill("parry", "lianhua-zhang");
	prepare_skill("strike", "lianhua-zhang");

        create_family("ؤ��", 20, "�������");

        set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
                "�Ƿ�" : "�ǡ����������������ҵ��£�\n",
                "ȫ����" : (: action_1 :),
        ]));
        setup();

        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
        carry_object(__DIR__"obj/gb_budai5")->wear();
}

int action_1()
{
        command("fear");
        return 1;
}
