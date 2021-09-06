// zhudanchen.c add some word for auto update.
// by cool 98.3.25
// Modify By River 98/11
#include <ansi.h>
#include <job_mul.h>

inherit NPC;

string ask_job();

void create()
{
        set_name("�쵤��", ({ "zhu danchen", "zhu", "danchen" }));
        set("title", "��������������ҽ�");
        set("gender", "����");
        set("age", 33);
        set("str", 27);
        set("dex", 26);
        set("long", "������������ȴ��һ������ģ��������������֦�йٱʡ�\n");
        set("combat_exp", 400000);
        set("shen_type", 1);
        set("unique", 1);
        set("no_bark",1);
        set("attitude", "peaceful");
        set("no_get", "�쵤��������˵̫���ˡ�\n");

        set_skill("strike", 90);
        set_skill("qiantian-yiyang", 100);
        set_skill("tianlong-xiang", 100);
        set_skill("qingyan-zhang", 80);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 20);
        map_skill("force", "qiantian-yiyang");
        map_skill("strike", "qingyan-zhang");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "qingyan-zhang");
        prepare_skill("strike","qingyan-zhang");

        set("max_qi", 900);
        set("max_jing", 500);
        set("eff_jingli", 500);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 20);
        set("inquiry",([
		"Ѳ��" : (: ask_job :),
        ]));

        setup();
        carry_object(__DIR__"obj/zipao")->wear();
}

void init()
{
        add_action("do_task","task");
}

string ask_job()
{
        object ob;
        ob=this_player();

        if (!ob->query_temp("dali_join"))
		return RANK_D->query_respect(ob)+"���㲻�Ǳ�������ӣ��˻��Ӻ�˵��";
        if (ob->query_temp("xuncheng"))
		return ("�㲻���Ѿ�����Ѳ�ǵ������𣿻�����ȥ����\n");
        if (ob->query("combat_exp") < 3000)
		return ("���书̫�ͣ��޷�ʤ��!��\n");
	if ( ob->query_condition("job_busy"))
		return RANK_D->query_respect(ob) + "����������񣬻�����ȥ��Ϣһ��ɡ�";
        if (ob->query("combat_exp") >= 150000)
		return "�ҿ�����书�����൱�Ĺ����ˣ��Ͳ���������������ˡ�";

        ob->set_temp("xuncheng",1);
        ob->apply_condition("job_busy", 2 + random(4));//busy ����һ��
        ob->apply_condition("dali_xuncheng2",random(5)+2);//һ��
	return "�ðɣ�����ڴ������Χ�Ĵ��鿴һ�£�Ѳ��ʱӦ��С�ķ�������ֹ��С�";
}

int do_task(string arg)
{
        object ob,me;
        int pot,exp,sil,shen,tb;
	string str = "";

        ob=this_player();
        me=this_object();
        if(!(arg||arg=="ok")) return 0;
        // ��ʦ����ר��
	if ( !wizardp(ob) ) {
	        if(!ob->query_temp("xuncheng"))
			return notify_fail("��ûѲ��������ʲô����\n");
	        if (interactive(ob)
	         && (int)ob->query_condition("dali_xuncheng2")) {
			command("angry "+ob->query("id"));
			return notify_fail(RED"����ô������ˣ��ǲ�����Щ�ط�ֻ��������������\n"NOR);
		}
	        if(!(ob->query_temp("dali_xc/xueshan")
	         && ob->query_temp("dali_xc/tianchi2")
	         && ob->query_temp("dali_xc/yuelong")
	         && ob->query_temp("dali_xc/ylf1")))
			return notify_fail("���ǲ���͵��������©��Щ�ط�ûѲ�� \n");
	        if(!(ob->query_temp("dali_xc/anning")
	         && ob->query_temp("dali_xc/dg3")
	         && ob->query_temp("dali_xc/xishuang")
	         && ob->query_temp("dali_xc/hg2")
	         && ob->query_temp("dali_xc/hg3")))
			return notify_fail("���ǲ���͵��������©��Щ�ط�ûѲ�� \n");
	        if(!(ob->query_temp("dali_xc/nianhuasimen")
	         && ob->query_temp("dali_xc/xs2")
	         && ob->query_temp("dali_xc/sl")
	         && ob->query_temp("dali_xc/yzh")
	         && ob->query_temp("dali_xc/ydxxxxxx")))
			return notify_fail("���ǲ���͵�����Ƕ�©��Щ�ط�ûѲ? \n");
	        if(!(ob->query_temp("dali_xc/caifeng")
	         && ob->query_temp("dali_xc/chaguan")
	         && ob->query_temp("dali_xc/xiulou")
	         && ob->query_temp("dali_xc/chouduan")
	         && ob->query_temp("dali_xc/xiyuan")
	         && ob->query_temp("dali_xc/yanzhi")
	         && ob->query_temp("dali_xc/datiepu")
	         && ob->query_temp("dali_xc/shudian")
	         && ob->query_temp("dali_xc/dafujia")
	         && ob->query_temp("dali_xc/zahuopu")
	         && ob->query_temp("dali_xc/shuyuan")
	         && ob->query_temp("dali_xc/huadian")
	         && ob->query_temp("dali_xc/yaopu")
	         && ob->query_temp("dali_xc/dangpu")
	         && ob->query_temp("dali_xc/yanju")
	         && ob->query_temp("dali_xc/duchang")
	         && ob->query_temp("dali_xc/qian")
	         && ob->query_temp("dali_xc/kedian")
	         && ob->query_temp("dali_xc/yizhan")
	         && ob->query_temp("dali_xc/mafang")))
			return notify_fail("���ǲ���͵��������©��Щ�ط�ûѲ? \n");
	}
        if(arg=="ok"){
		command("pat "+ob->query("id"));
		command("say ����������Ϊ���ˣ�"+RANK_D->query_respect(ob)+"�������úã�");
		sil = (int)(ob->query_skill("force",1)/10)+random(5);
                exp = random(45)+ob->query("max_pot")/2;
				
		exp = ob->add_exp_combat(exp,me,"Ѳ��");
//�����ӱ�
       ob->add("combat_exp",exp);  
       
       pot = exp/5 + random(exp/10);
		pot = pot*4;//����job pot ��� ciwei
		
		me->add_money("silver",sil);
		command("give "+ob->query("id")+" "+sil+" silver");
		ob->add("potential",pot);
		shen = exp/2 + random(exp/2);
		if( ob->query("shen") < -1000 ) {
			ob->add("shen", -shen);
			str = "��";
		}
		else if( ob->query("shen") > 1000 ) {
			ob->add("shen",  shen);
			str = "��";
		}
		else if ( ob->query("shen") <= 1000 && ob->query("shen") >= -1000)
			shen = 0;
   //              if(ob->query("potential") > ob->query("max_pot"))
   //                     ob->set("potential", ob->query("max_pot"));             
		ob->add("job_time/����",1);		
		
		tell_object(ob,HIW"�㱻�����ˣ�"+
			chinese_number(exp) + "��ʵս���飬" +
			chinese_number(pot) + "��Ǳ�ܣ�"+
			chinese_number(sil)+"��������"+
          chinese_number(shen)+"��"+str+"��\n"NOR);             


 tell_object(ob,HBRED"���ֽ����ڼ䣬��������ˣ�"+chinese_number(exp) + "��ʵս���飡"+chinese_number(tb) +"���齣ͨ����\n"NOR); 
		ob->delete_temp("xuncheng");
		ob->delete_temp("dali_xc");
		return 1;
	}
	return 0;
}
