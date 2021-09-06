inherit NPC;

void create()
{
        set_name("�嶾�̵���", ({ "wudujiao dizi", "dizi"}));
        set("long", 
                "һ����ͨ���嶾��Ů���ӡ�\n");
        set("gender", "Ů��");
	set("age", 15 + random(10));
        set("attitude", "peaceful");
        set("shen", -1000);
   
        set("str", 30);
        set("int", 20);
        set("con", 24);
        set("dex", 24);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 20);
        set("combat_exp", 50000 + random(20000));

        set_skill("force", 50);
        set_skill("yinyun-ziqi", 50);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 60);
        set_skill("strike", 60);
        set_skill("chousui-zhang", 60);
        set_skill("parry", 60);
        set_skill("poison", 80);

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "chousui-zhang");


        create_family("�嶾��", 3, "����");

        setup();

        carry_object("/clone/armor/cloth")->wear();
}
