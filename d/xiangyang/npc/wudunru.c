// wudunru.c�����
// Lklv modify 2001.9.22

inherit NPC;
void consider();

void create()
{
        set_name("�����", ({ "wu dunru","wu","dunru" }) );
        set("gender", "����" );
        set("age", 28);
        set("long", "��Ľ�׳��ŨŨ��üë��һ�������������ӡ�\n");
        set("attitude", "peaceful");
        set("str", 30);
        set("con", 30);
        set("int", 20);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);

        set("combat_exp", 1000000);

        set_skill("force", 160);
        set_skill("hand", 160);
        set_skill("blade", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("huntian-qigong", 160);
        set_skill("literate", 160);
        set_skill("suohou-shou", 160);
        set_skill("liuhe-daofa", 160);
        set_skill("xiaoyaoyou", 160);


        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("blade","liuhe-daofa");
        map_skill("hand", "suohou-shou");
        map_skill("parry", "liuhe-daofa");
        prepare_skill("hand", "suohou-shou");

        set("inquiry", ([
//                "�س�": (: ask_job :),
        ]) );

        create_family("ؤ��", 19, "��������");

        setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("changshan4"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
