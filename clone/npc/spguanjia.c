/**********************************************************************************
//
//      spguanjia.c
//      Created by mychat 02/05/2004
//      �����ҵ�ǩ������� free of use.
//      ��Ȼ����ӭ�޸ġ��Ż��ȡ�
//
//      Email & MSN: codemake@163.com
//      �ļ�λ��/clone/npc��
// 		������ⷿ�任���Ƶ�����
***********************************************************************************/

inherit NPC;

void create()
{
	set_name("���̹ܼ�", ({ "shangpu guanjia" }));

	set("gender", "����");
	set("age", 65);
	set("no_quest", 1);
	set("no_drop", 1);
	set("no_get", 1);
	set("gender", "����");

	set("combat_exp", 7500);
        set_skill("unarmed", 35);
        set_skill("force", 35);
        set_skill("dodge", 40);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);

	set("combat_exp", 5000000);

	set("inquiry", ([
		"name": "���ǰ�Τ��ү�ɻ�ģ����������Լҳ���ĵ��������Ƿ񻹺�",
	]) );
	set("attitude", "friendly");

	setup();
	set_weight(0);
}

void init()
{
	::init();
	if(query("work_over")) return;
	set("work_over",1);
	if ( base_name(environment())==query("target") )
		if( environment()->change_rsname() ) message_vision("ֻ��$N���Ż��ߺ�ȣ����ϰ��ˣ����첻�����ƻ��ˡ�\n", this_object());	
	call_out("dest", 10, this_object());
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��ɥ�ط������̹ܼҺ���֪��������ʲô�£�������æ�Լ����¡�\n", ob);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say("���̹ܼҿ�Ц��˵����ֻ�ǰ�Τ��ү�ɻ��С��������ο����һ���ʶ\n");
	command("hehe");
}

void die()
{
	unconcious();
}


void dest(object ob)
{
	if ( !ob ) return;
    	if (ob->is_character() ){
    		if( environment(ob))
       			message_vision("ֻ��$Næ�����е����飬���Ų�æ�����ˡ�\n", ob);  
       	}
       	
       	destruct(ob);
}