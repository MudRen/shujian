//tz_job1.c
#include <ansi.h>

string *names = ({"��կ��","���ݾ�","��ľ",});

string ask_job1()
{
        object me;
        object ob;
        string target;
        mapping fam;
        ob=this_player();
        me=this_object();
        fam = ob->query("family");
        
        if(!fam || fam["family_name"] != "���ư�")
		return "�㲻���Ұ���ӣ��ٺ�....�������Ǹɻ�ǲ�����������ưﵱ��ϸ��\n";
        if (ob->query_temp("job_name"))
		return ("�㲻���Ѿ����˹����𣿻�����ȥ����\n");
        if (ob->query("combat_exp")>100000)
		return ("�������ư��Ѿ���һ��ʱ���ˣ�����û���ʺ����������Ըɡ�\n");
        if ( (int)ob->query_condition("tz_job") || ob->query_condition("job_busy"))
                return RANK_D->query_respect(ob)+ "����û��ʲô�¿���������ʱ�������ɡ�";
        target = names[random(sizeof(names))];
        ob->set_temp("job_name",target);
        ob->apply_condition("tz_job", random(5)+10);
        ob->apply_condition("job_busy", 6);
        return "���ư��Ҫ��ֹ�ٸ������ǵ���ˣ���Ҫ��ֹ�����������ɶ����ǰ���Ѱ��\n"+
		"���书��΢����ȥ" + target + "�ɡ�";
}

int do_task(string arg)
{
        int pot,exp,shen,money;
        object ob,me;
        ob=this_player();
        me=this_object();

        if( !arg || arg !="ok") return 0;

        if(!ob->query_temp("job_name")) 
            return notify_fail(CYN"��ǧ��������ü��˵����û���㹤��������ô���������ˣ�\n"NOR);

        if(!ob->query_temp("mark/����")) 
            return notify_fail(CYN"��ǧ��˵�������Ȱѹ��߻��ع��߷������������ɡ�\n"NOR);

        if(!(ob->query_temp("mark/����")||ob->query_temp("mark/����")
           ||ob->query_temp("mark/����")))
            return notify_fail(CYN"��ǧ��˵������͵����������ɻ��㲻ȥ�ɣ������칦! \n"NOR);

        if( arg=="ok" 
         && (ob->query_temp("mark/����")
           || ob->query_temp("mark/����")
           || ob->query_temp("mark/����"))){
		command("haha "+ob->query("id"));
		command("thumb"+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"���Ǹ���Ľ��ͣ�");
		money =(int)(ob->query_skill("guiyuan-tunafa",1)/10)+random(5);
		exp =random(30)+ob->query("max_pot")/2;
		if( ob->query_temp("mark/done"))
			exp += 50 +random(30);
		exp = ob->add_exp_combat(exp,this_object(),"����");
		pot = exp /5 + random(exp/10);
		shen =random(200)+ob->query("max_pot")/2;
		me->add_money("silver",money);
		command("give "+ob->query("id")+" "+ money +" silver");
		ob->add("potential",pot);
		if(ob->query("potential") > ob->query("max_pot")) 
			ob->set("potential", ob->query("max_pot"));
		//ob->add("combat_exp",exp);
		ob->add("shen",-shen);
		tell_object(ob,HIW" �㱻�����ˣ�\n" + 
			chinese_number(exp) + "��ʵս����\n"+
			chinese_number(pot) + "��Ǳ��\n"+
			chinese_number(shen)+ "����\n"NOR);
		ob->delete_temp("job_name");
		ob->delete_temp("mark");        
		return 1;
	}
	return 1;
}
