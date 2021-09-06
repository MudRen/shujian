// Npc songshan shi.c ʷ�Ǵ�
// Modify by baimo 2000,12,11 for a new job
// shi.c ��ɽ�ɵ��Ĵ����� ʷ�Ǵ�
// Lklv 2001.10.18 Modified

#include <ansi.h>
inherit NPC;
int ask_job();
string ask_fangqi();

void create()
{
        set_name("ʷ�Ǵ�", ({ "shi dengda", "shi", "dengda" }));
        set("long", "������������ͽ�ܣ�����λ������ߵĻ������ӡ�\n");
        set("gender", "����");
        set("age", 26);
        set("per", 20);
        set("attitude", "heroism");
        set("class", "songshan");
        set("shen_type", -1);
        set("str", 23);
        set("int", 20);
        set("con", 23);
        set("dex", 23);
        set("unique", 1);

        set("max_qi", 1400);
        set("max_jing", 1000);
        set("eff_jingli", 1000);
        set("jiali", 20);
        set("combat_exp", 700000);
        set("shen", -7000);

    	set_skill("force", 110);
    	set_skill("hanbing-zhenqi", 110);
    	set_skill("dodge", 100);
    	set_skill("zhongyuefeng", 100);
        set_skill("hand", 100);
        set_skill("songyang-shou", 100);
    	set_skill("parry", 100);
    	set_skill("sword", 100);
    	set_skill("songshan-jian", 100);
    	set_skill("literate", 50);

    	map_skill("force", "hanbing-zhenqi");
    	map_skill("dodge", "zhongyuefeng");
        map_skill("hand", "songyang-shou");
    	map_skill("parry", "songshan-jian");
    	map_skill("sword", "songshan-jian");
        prepare_skill("hand", "songyang-shou");

    	create_family("��ɽ��", 4, "����");
        set("inquiry", ([
		"job" :( : ask_job :),
		"����" :(: ask_job :),
		"fangqi":(: ask_fangqi :),
		"����" :(: ask_fangqi :),
		"��ɽ��" : "������ɽ������������֮�ף�\n",
		"��������" : "������������������֮�������޴󣬿������֡��䵱���⡣\n",
		"������" : "���������ǵ������ˣ�������ɲ⡣\n",
	]) );
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();
        carry_object(BINGQI_D("changjian"))->wield();
}

int ask_job()
{
	object me = this_player();

        if (me->query("family/family_name")!="��ɽ��" ){
                command("say �㲻������ɽ���ӣ���������Ъ��ȥ�ɣ�\n");
                command("sneer");
                return 1;
        }
        if (me->query("combat_exp") >= 30000){
		command("say ��Ĺ����Ѿ��ܸ��ˣ�������ȥ�Ҷ�û���ӡ�\n");
		return 1;
	}
	if (me->query_temp("ss_qs/asked")){
		command("say ��ղŲ����ʹ�������ô����ȥ��\n");
		return 1;
	}
	if (me->query_condition("job_busy")){
		command("say ����ͷ�����������°ɣ���һ�������ɣ�\n");
		return 1;
	}
	me->set_temp("ss_qs/asked",1);
	me->apply_condition("job_busy",4);
	message_vision(HIC"ʷ�Ǵ�˵���������ٿ�Ӣ�ۻ���Ҫ��������̨��$N��ȥ��ʤ���æ��ʯ��\n"NOR,me);
	return 1;
}

string ask_fangqi()
{
        object me = this_player();

        if(me->query("family/family_name")!="��ɽ��")
              return "�����ɽ�ɵ���,������Ϲ����ʲ��?";
        if(!me->query_temp("ss_qs/asked"))
              return "ʲô��������ʲô����";
        me->delete_temp("ss_qs");
        me->clear_condition("job_busy");
        me->start_busy(1);
        me->apply_condition("job_busy",3+random(3));
        return "�ðɣ������Ъ���ȣ�";
}
#include "app4.h";