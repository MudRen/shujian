//kuang.c  ������

inherit NPC;

void create()
{
        set_name("������", ({ "kuang baoguan", "kuang" }));
        set("long","�����ŷ�ɽ��������������㣬�������ţ�¶�����맵����Գ�ë��\n");
        set("gender", "����" );
        set("age", 33);
	set("attitude", "peaceful");
	set("shen", -1000);

	set("str", 22);
        set("int", 25);
        set("con", 22);
        set("dex", 21);

	set("max_qi", 150);
        set("max_jing", 150);
        set("neili", 150);
        set("max_neili", 150);

        set("jingli",100);
          set("eff_jingli",100);
        set("jiali", 30);   
	set("combat_exp", 8000);

	set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("strike", 20);
        set_skill("parry", 20);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
