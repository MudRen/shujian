// dizi3.c

inherit NPC;

void create()
{
        set_name("������ؤ", ({ "qigai", "beggar" }) );
        set("long","����һ��������ؤ���������в������ơ�\n");
	
        set("gender", "����");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);


        setup();

}

