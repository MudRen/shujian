//fengqi.c  ����

inherit NPC;

void create()
{
        set_name("����", ({ "feng qi", "feng" }));
        set("long", "���Ƿ����ϵ�Զ����ܣ�������Ӣ�۾�¥���ƹ��书��û��ʲô��
Ϊ��ȴ���ǻ��顣\n");
	set("shen_type", 1);
        set("gender", "����" );
        set("age", 31);
	set("attitude", "friendly");
        
	set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

	set("max_qi",200);
        set("max_jing",200);
        set("neili",200);
        set("max_neili",200);

        set("jingli",200);
        set("eff_jingli",200);
        set("jiali", 1);   
	set("combat_exp", 20000);

        set_skill("cuff", 30);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);

        add_money("silver", 50);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

