// lu-liding.c

inherit NPC;

void create()
{
        set_name("½����", ({ "lu liding", "lu" }) );
	set("gender", "����" );
        set("age", 35);
	set("long", "������½չԪ֮��½������\n"+
		 "һ���书�����ֳ�½չԪ���������Ե�����һ��ϯ���ĺ񣬴Ӳ������������ߡ�\n");
	set("attitude", "friendly");
        set("str", 22);
        set("dex", 24);
        set("con", 20);
        set("int", 20);
        set("per", 26);
        set("shen_type", 1);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("blade", 80);
        set("jiali", 20);

        set("combat_exp", 100000);

        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("max_jingli", 200);

        set("inquiry", ([
		"�����" : "����ɩ�ӡ�",
		"½չԪ" : "���������ֳ���",
	]));

	setup();

        carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}
