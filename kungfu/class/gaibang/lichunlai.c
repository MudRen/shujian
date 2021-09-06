// lichunlai.c ���
// Lklv 2001.9.28 update for open ���Ƿֶ�

inherit NPC;
#include "begger.h";

void create()
{
        set_name("���", ({"li chunlai", "li", "chunlai" }));
        set("title", "ؤ����Ƿֶ��Ĵ�����");
        set("gb/bags", 4);
        set("gender", "����");
        set("age", 32);
        set("long", "����ؤ���Ĵ����ӣ����Ƿֶ����°��ڡ�\n");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 22);
        set("con", 20);
        set("dex", 21);

        set("qi", 2100);
        set("max_qi", 2100);
        set("jing", 1400);
        set("max_jing", 1400);
        set("eff_jingli", 2400);
        set("neili", 1600);
        set("max_neili", 1400);
        set("jiali", 50);

        set("combat_exp", 800000);

        set_skill("force", 120); // �����ڹ�
        set_skill("huntian-qigong", 120); // ��������
        set_skill("strike", 120); // ����ȭ��
        set_skill("dodge", 120); // ��������
        set_skill("xiaoyaoyou", 120); // ǧ������
        set_skill("parry", 120); // �����м�
        set_skill("begging", 120);
        set_skill("lianhua-zhang", 120);

        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
	map_skill("strike", "lianhua-zhang");
	map_skill("parry", "lianhua-zhang");
	prepare_skill("strike", "lianhua-zhang");

        create_family("ؤ��", 20, "�Ĵ�����");

        set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
                "�Ƿ�" : "�ǡ����������������ҵ��£�\n",
                "ȫ����" : "���Ƕ������ѵ��㲻֪���\n",
        ]));
        setup();

        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
        carry_object(__DIR__"obj/gb_budai4")->wear();
}
