//dizi7.c ��̹ by river
//��ԭ�е�di yun�����ݰᵽ����
//by tangfeng for ���Ǿ�quest

inherit NPC;

#include <ansi.h>
#include "question.h"
#include "/d/suzhou/npc/lchj.h";

void create()
{
	set_name("��̹", ({ "feng tan", "feng", "tan"}));
	set("title","��������ߵ���");
	set("long", "��������ɽ���ߵ��ӣ���Ĭ���ԣ�һ��������������ӡ�\n");
	set("gender", "����");
	set("age", 22); 

	set("combat_exp", 5000);
	set("shen_type", 1);
	set("unique", 1);

	set_skill("force", 35);
	set_skill("strike", 35);
	set_skill("sword", 35);
	set_skill("shenzhao-jing",35);
	map_skill("force", "shenzhao-jing");          

	set("startroom","/d/wuguan/dayuan");

	set("chat_chance", 3);
	set("chat_msg", ({            
		(: random_move :)
	}) );
       
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object *inv, where;

	if (!ob) return;
	where = environment(ob);
	if( !ob || environment(ob) != environment() ) return;        
	if ( ob->query("combat_exp") > 3500 && !wizardp(ob) && !ob->query_temp(QUESTDIR2+"start") ){
		command("disapp "+ ob->query("id"));
		command("say ��λ" + RANK_D->query_respect(ob)+ "�����Ѿ��ܵ�����Ľ�����ȥ����һ���ˣ���ô����\n"+
			"�������͵������ݲ�ϣ���������ڴ˵��ˡ�\n");
		message_vision(HIR"ֻ����һ�����˰���$N��һ������������ˡ�\n"NOR, ob);
		ob->delete("enter_wuguan");
		inv = filter_array(deep_inventory(ob), (: userp :));
		if( sizeof(inv))
			inv->move(where);
		ob->unconcious();
		ob->delete_temp("quest/busy");//
		ob->delete_temp("quest/���Ǿ�");
		ob->move("/d/xiangyang/damen");
		return;
	}
	if( ! ob->query_temp("wgtask") && ob->query("combat_exp") < 400 ) {
		ob->set_temp("wgtask",1);
		ob->set_temp("wgmeet", 1);
		command("bow "+ob->query("id"));
		command("whisper "+ob->query("id")+" ��λ" + RANK_D->query_respect(ob) +"��������������ص��������磬�ǲ���\n"+
			"�о������������İ�����ҿ��Ը���������������Ϥ�������ģ��������Ƿ�\n"+
			"��Ҫ�����أ�������Ǹ����֣������� "HIY HBCYN"answer y"GRN"������������� "HIY HBCYN"answer n"GRN"��");
	}
	if( ob->query_temp("jobover") == 1) {
		ob->set_temp("jobask",2);
		command("pat "+ob->query("id"));
		command("whisper "+ ob->query("id")+ " ���ڶ��Լ�����ݵĻ�����һ���˽��˰ɣ�������\n"+
			"���˽���Χ�Ļ�������������Ҫ�˽����������������У�����ʦ�ֳ��괳��\n"+
			"������֪���ıȽ϶࣬�����ȥ�������ʡ���������ƫ��һ��������԰�����\n"+
			"����ֵܸ��������ݵ�ͼ��help map wuguan��ȥ������");
	}
	if( ob->query_temp("jobover") == 2) {
		ob->set_temp("jobask",3);
		command("smile "+ob->query("id"));
		command("whisper "+ ob->query("id")+ " �˽����������磬�ǲ��Ǹо����Ĳ������뵽����\n"+
			"����һ����Ϊ�أ���ô��ȥ�������ʦ��ѧϰ��ս��֪ʶ�ɡ���������������\n"+
			"�����������ء�"NOR);
	}
	if( ob->query_temp("jobover") == 3) {
		ob->set_temp("jobask",4);
		command("hehehe");
		command("whisper "+ ob->query("id")+ " ���߽�������ƾ���¶����ǲ��еģ���Ҫע�����\n"+
			"�Ҷ�ཻ��Ŷ����ʦ�����߶�������ġ����칦��������ȥ����׼û��\n"+
			"��������˯�������������������������ء�"NOR);
	}
	if( ob->query_temp("jobover") == 4 && ob->query_temp("jobask") != 5) {
		ob->set_temp("jobask", 5);
		command("nod");
		command("whisper "+ ob->query("id")+ " ���ˣ��������Ѿ����齣Ҳ�˽�Ĳ���ˡ����\n"+
			"�л��кܶ�����Ҫ������³��ʦ����ȱ���֣�����Ե������ҵ㹤��������");
	}
	if( ob->query("combat_exp") < 3000 && ob->query_temp("jobover") == 5) {
		command("pat " +ob->query("id"));
		tell_object(ob, CYN"��̹˵��������λ" + RANK_D->query_respect(ob) +"���ҳ��������⿼���㣬�������˿��н�Ŷ����\n"NOR);
		tell_object(ob, WHT"\n���ȷ�ϻش����⣬������ "HIY HBCYN"answer y"WHT" ����Ը��ش�Ļ������Լ���ȥ³��ʦ\n"+
				"��������������������� "HIY HBCYN"answer n"WHT" ��\n\n");
		ob->set_temp("wgquestion",1);
	}
	return;
}
string replace_number(string msg)
{
	msg = replace_string(msg, "һ", "a");
	msg = replace_string(msg, "��", "b");
	msg = replace_string(msg, "��", "c");
	msg = replace_string(msg, "��", "d");
	msg = replace_string(msg, "��", "e");
	msg = replace_string(msg, "��", "f");
	return msg;
}

string *answer_type;

mixed choose_type(object me, string *answer, int j, string right_answer)
{
	int x, y;
	string str;

	for ( x = 0; x < j ; x ++) {
		str = answer[random(j)];
		answer_type = me->query_temp("answer_type");
		if ( ! sizeof(answer_type))
			me->set_temp("answer_type", ({ str }));
		else {
			for(y=0; y < j; y ++) {
				if (member_array(str, answer_type) != -1)
					str = answer[y];
			}
			answer_type = answer_type + ({ str });
			me->set_temp("answer_type", answer_type );
		}
		if ( str == right_answer )
			me->set_temp("answer", replace_number(chinese_number(x+1)));
	}
	return answer_type;
}

int do_question(object me)
{
	string right_answer, str, *answer;
	int i, j, x;
	mapping question;

	if ( me->query_temp("answer_list") && sizeof(keys(me->query_temp("answer_list"))) >= sizeof(question_list)) {
		command("say ������˼��û����Ŀ�ˡ�");
		return 1;
	}

	i = random(sizeof(question_list));

	if ( me->query_temp("answer_list/"+ i) )
		do_question(me);
	else {
		me->set_temp("answer_list/"+ i , 1);

		question = question_list[i];
		answer = question["choose"] + ({ question["answer"] });
		right_answer = question["answer"];

		j = sizeof(answer);

		choose_type(me, answer, j, right_answer);

		me->add("wgjob/quest", 1);

		tell_object(me, CYN"\n��̹˵�����������ǵ�"+chinese_number(me->query("wgjob/quest"))+"�⣬һ����"+chinese_number(j)+"��ѡ����� "HIY HBCYN"answer ��ĸ"CYN" �ش𡣡�\n"NOR);
		str = "���ʣ�" + question["question"] +"\n";

		for ( x = 0; x < j ; x ++ ) {
			str += sprintf("%s��%-31s%s", 
				capitalize(replace_number(chinese_number(x+1))), 
				answer_type[x], 
				(x+1)%2?"":"\n"
			);
		}

		if ( j % 2)
			str += "\n";
		tell_object(me, str);
		return 1;
	}
}

int do_answer(string arg)
{
	object me = this_player();
	string str;
	float i;

	if ( ! arg ) return 0;
	if ( me->query_temp("wgmeet")) {
		me->delete_temp("wgmeet");
		if ( arg == "y" ) {
			command("nod "+ me->query("id"));
			command("whisper " + me->query("id")+ " �Ǻã����������˽�һ��һЩ������ָ����齣\n"+
				"���ƶ���������e��w��s��n��u��d���ֱ�������ϱ�������������������\n"+
				"��ne��wd��su��enter��out����Ϻ�����������Ƿֱ�����������¡���\n"+
				"�ϵȷ����Լ����������ȡ����ˣ����������ȥ��������������������\n"+
				"��ʶ��������Ӧ��������һ���������������͵��ˡ�");
			me->set_temp("jobask",1);
			me->set_temp("need_answer", 1);
		}
		else if ( arg == "n" ) {
			command("nod "+ me->query("id"));
			command("whisper " + me->query("id")+ " ��������齣�Ѿ�����һ�����˽⣬����ﻹ�к�\n"+
				"������Ҫ������³��ʦ����ȱ���֣�����Ե������ҵ㹤��������");
			me->set_temp("jobask", 5);
		}
		return 1;
	}
	if ( me->query_temp("wgquestion")) {
		me->delete_temp("need_answer");
		me->delete_temp("wgquestion");
		me->delete_temp("jobover");
		if ( arg == "y") {
			tell_object(me, CYN"��̹˵�������ðɣ������ڻش�����ǰ���һ���Ҫ��������һ�£������ͨ��\n"+
					"ָ�� "HIY HBCYN"help"CYN" ���˽�һ���齣��һЩ��������������һЩ���⣬�����ͨ����\n"+
					"ѯ help ���õ���ȷ�Ĵ𰸣����ʵ���Ҳ����𰸣�Ҳ����ͨ�� "HIY HBCYN"chat"CYN" ��ѯ��\n"+
					"�������õ��𰸡���\n"NOR);
			tell_object(me, HIR"\n\t\t׼�����˰ɣ������ǾͿ�ʼ�ˡ�\n\n"NOR);
			call_out("do_question", 0 , me);
		}
		else if ( arg == "n" ) {
			tell_object(me, CYN"��̹˵����������������Ȼ�㲻��ش���Ҳ�����ˡ���\n"NOR);
		}
		return 1;
	}
	if ( me->query_temp("answer")) {
		if ( arg == "��ĸ")
			return notify_fail(CYN"��̹˵��������ش�������ĸ������ش�"HIY HBCYN"answer A"CYN" ����\n"NOR);
		if ( arg == me->query_temp("answer") || arg == capitalize(me->query_temp("answer"))) {
			me->add("combat_exp", 80 );
			me->add_temp("right", 1);
			if ( me->query_skill("literate", 1) < 30 ) {
				me->set_skill("literate", me->query_skill("literate", 1) + 1);
				str = "��һ������д�֡�";
			}
			else
				str ="��";
			i = me->query_temp("right")*100.0 / me->query("wgjob/quest");
			tell_object(me, HIW"��ϲ�㣬����ˣ��㱻�����˰�ʮ��ʵս����"+str+"\n"NOR);
			tell_object(me, CYN"��̹˵����������Ŀǰһ���ش���"+chinese_number(me->query("wgjob/quest"))+"�⣬�����"+chinese_number(me->query_temp("right"))+"�⣬�ɹ���Ϊ "+sprintf("%3.2f%%", i)+"����\n"NOR);
		}
		else tell_object(me, CYN"��̹˵�������������ϧ�������ˣ���ȷ��Ӧ���� "+capitalize(me->query_temp("answer"))+" �Ŷԡ���\n"NOR);

		me->delete_temp("answer");
		me->delete_temp("answer_type");

		if ( me->query("combat_exp") < 3000 && me->query("wgjob/quest") < 50 ) 
			do_question(me);
		else {
			if ( me->query("combat_exp") >= 3000 ) {
				command("congra "+me->query("id"));
				tell_object(me, CYN"��̹˵�����������ȥ����ʦ������ɽѯ����ݵ������� "HIY HBCYN"ask wan about ���"CYN" ����\n"NOR);
			}
			else {
				command("addoil "+ me->query("id"));
				tell_object(me, CYN"��̹˵����������Լ���ȥ���Ҵ�ʦ���Ƕ��ҹ����� "HIY HBCYN"ask lu about ����"CYN" ����\n"NOR);
			}
		}
		return 1;
	}
	return 0;
}

