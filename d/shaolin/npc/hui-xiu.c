// Npc: /kungfu/class/shaolin/hui-xiu.c
// Date: YZC 96/01/19

inherit NPC;
string ask_me();

void create()
{
	set_name("��������", ({
		"huixiu zunzhe",
		"huixiu",
		"zunzhe",
	}));
	set("long",
		"����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

        set("age", 50);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 450);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
 
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 100);

        set_skill("force", 70);
        set_skill("hunyuan-yiqi", 70);
        set_skill("dodge", 70);
        set_skill("shaolin-shenfa", 70);
        set_skill("cuff", 75);
        set_skill("jingang-quan", 75);
        set_skill("staff", 76);
        set_skill("pudu-zhang", 76);
        set_skill("parry", 70);
        set_skill("buddhism", 70);
        set_skill("literate", 70);
   	map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("staff", "pudu-zhang");
        map_skill("parry", "pudu-zhang");

        prepare_skill("cuff", "jingang-quan");



	create_family("������", 38, "����");
        set("inquiry", 
                ([
                     	"��ֵ" : (: ask_me :),
                ]));
	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
#include "/kungfu/class/shaolin/hui.h"

void init()
{
	add_action("do_tast","task");
}
string ask_me()
{
        mapping fam; 
        object ob;
        ob=this_player();
        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "������")
                return RANK_D->query_respect(ob) + 
                "���㲻�Ǳ��µ��ӣ��˻��Ӻ�˵��";
        if ((string)ob->query("class")!="bonze")
            return ("�׼ҵ��Ӳ�����ֵ��");
        if (ob->query("combat_exp")>=50000)
                return ("�ҿ�����书�����൱�Ĺ����ˣ��Ͱ���ֵ�Ļ����ø�ʦ���ǰɡ�\n");
	if (ob->query_temp("lunzhi"))
		return ("������������ֵ�ˣ���͵���һ�ΰɡ�\n");
       
	ob->set("lunzhi_name",ob->query("name"));
	//me->set_temp("lunzhi",1);
	ob->set_temp("lunzhi",1);
	ob=new("/d/shaolin/npc/obj/lunzhi-ling");
	ob->move(this_player());
	write("���޴�ʦ����һ����ֵ�\n");
        return "�ðɣ���͵�ӭ��ͤ�������ͨ�ɣ���ֵʱӦ��С�ķ�������ֹ���͵�����С�";
}
int do_tast(string arg)
{
	object ob,me;
	ob=this_player();
	me=this_object();
	if(!(arg||arg=="ok")) return 0;
	if(!ob->query_temp("lunzhi")) return 0;
	if(!ob->query_temp("lunzhied")) return 0;
	if(arg=="ok"&&ob->query_temp("lunzhied")
		&&ob->query("name")==me->query("lunzhi_name"))
	{
             
              if (interactive(ob = this_player()) && 
            	(int)ob->query_condition("sl_lunzhi")) {
                 command("angry"+ob->query("id"));
                 command("slap"+ob->query("id"));
                 return notify_fail("��͵��������ҹ���ȥ��");
                 }          
                command("pat "+ob->query("id"));
		command("say ����������Ϊ���ˣ�"+RANK_D->query_respect(ob)+"���ɵúã�");
                  ob->add("potential",(int)(ob->query_skill("buddhism",1)/10)+10);
		if (ob->query("potential") > ob->query("max_pot"))
                  ob->set("potential", ob->query("max_pot"));   
                ob->add("combat_exp",(int)(ob->query_skill("buddhism",1)/4)+100);
                me->delete("lunzhi_name");
		me->delete_temp("lunzhi");
		ob->delete_temp("lunzhi");
		ob->delete_temp("lunzhied");
		return 1;
	}
	return 1;
}