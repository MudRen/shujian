// Modify By River 98/12

inherit NPC;

void create()
{
        set_name("��ü����", ({ "huangmei heshang", "heshang", "huangmei" }) );
        set("title", "�黨������");
        set("gender", "����" );
        set("age", 65);
        set("str", 25);
        set("con", 23);
        set("dex", 23);
        set("int", 20);
        set("unique", 1);

        set("max_qi", 2500);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("max_neili", 2500);
        set("jiali", 100);       

       create_family("��������������", 10, "����");
        set("long", 
        "һ���������ơ����θߴ����ɮ������ɮ�������Ƴ�ü��üβ�´���\n");

        set("combat_exp", 1000000);
        set("score", 20000);       

        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("force", 120);
        set_skill("finger", 150);
        set_skill("buddhism", 120);
        set_skill("literate", 120);
        set_skill("yijin-jing", 120);
        set_skill("nianhua-zhi", 160);
        set_skill("shaolin-shenfa", 150);
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "nianhua-zhi");
        map_skill("finger", "nianhua-zhi");
        map_skill("force", "yijin-jing");
        prepare_skill("finger","nianhua-zhi");      

        setup();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}
