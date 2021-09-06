//dizi4.c ��� by river

#include <ansi.h>
inherit NPC;
int ask_wuguan();
int ask_liguan();
int ask_xuexi1();

void create()
{
	set_name("���", ({ "sun jun","sun","jun", "man" }));
	set("title", "��������ĵ���");
	set("gender", "����");
	set("age", 21);
	set("long", "��������ɽ���ĵ��ӣ���ò�Ͱ���һ�쵽��Ц�Ǻǵġ�\n");
	set("combat_exp", 5000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("unique", 1);

	set_skill("force", 50);
	set_skill("strike", 50);
	set_skill("sword", 50);
	set_skill("shenzhao-jing",50);
	map_skill("force", "shenzhao-jing");

	set("inquiry", ([
		"����ɽ" : "�����˼����ҵĶ�ʦ����",
		"���" : (:ask_liguan:),
		"���" : (:ask_wuguan:),
		"�������" :(:ask_wuguan:),
		"ѧϰ" : (:ask_xuexi1:),
	]));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ( ob ->query("combat_exp") < 500 && ob->query_temp("jobask") == 1){
		command("bow "+ob->query("id"));
		command("say ��λ" + RANK_D->query_respect(ob) +",����� "HIY HBCYN"ask sun about ѧϰ"CYN" �������˽���ݵ������"NOR);
		
	}
}

int ask_xuexi1()
{
	object ob = this_player();
	if( ob->query_temp("jobask") == 1 ) {
		command("say �㲻���Ĵ�����"HIY HBCYN"look"CYN"��������ʲô�����㶼���Լ�����"HIY HBCYN"get"CYN"���š�\n"+
		"������Ȳ��"HIY HBCYN"i or inventory"CYN"����������������Щʲô����Ҫ��ʱ�ز��"HIY HBCYN"hp\n"+
		CYN"�������״̬��Ҫ�Ƕ��˻���˾�ȥ��Щ�Եĺȵİɡ���Ҫ����ʲô�����\n"+
		"�����ҡ�"HIY HBCYN"ask sun about ������ݣ�ask sun about ���"CYN"��\n"+
		"���ڸ���ָ��ľ����÷����Բο� "HIY HBCYN"help commands"CYN"��"NOR);
		ob->delete_temp("jobask");
		if(ob->query_temp("jobover") != 1) {
			ob->set_temp("jobover", 1);
			command("say ��˵�����ֵ��е��������㣬�����ȥ��һ�¡�"NOR);
			if ( ob->query("combat_exp") < 100) {
				ob->add("potential", 20);
				ob->add("combat_exp",100);
				tell_object(ob,HIW"����������Ľ��⣬������һ�ٵ�ʵս����Ͷ�ʮ��Ǳ�ܣ��Խ����ֶ���һ���˽⡣\n"NOR);
			}
		}
		return 1;
	}
	if ( ob->query_temp("jobover") == 1) {
		command("say �Ҳ��Ƕ�����˵��ô�������ֵ��������㣬��ȥ���°ɡ�");
		return 1;
	}
}

int ask_wuguan()
{
	object ob = this_player();
	if (ob ->query("combat_exp") < 1000){
		command("say  �������������ʦ���������֡�����ɽ�����˼�һ�ֽ����ģ�����\n"+
		"������Ŀ�ľ����ڸ�һЩ���뽭��������һЩ������ʵ���Ļ��ᡣ����������\n"+
		"���� "HIY HBCYN"help wuguan"CYN" �� "HIY HBCYN"help map_wuguan"CYN"��"NOR);
		return 1;
	}
	else{
		command("kick "+ ob->query("id"));
		command("say �������ô��ʱ���ˣ����ڸ��𰡣��Լ���Ϥȥ�ɣ�\n");
		return 1;
	}
}

int ask_liguan()
{
        object book,vipcard,quanpu, ob = this_player();
        if (!ob->query("enter_wuguan") && ! ob->query("get_newbie")){
		command("congra "+ob->query("id"));
		command("say ��λ" + RANK_D->query_respect(ob)+"���Գ�ȥ���������ˣ������ն񣬿�ǧ��С�İ���������\n"+
                "�͵�����ݣ���������Գ˳����������ɣ�����ݾ��������ˡ�\n"+
                "����������������书��΢���������Ҹ��ط�ĥ��һ�±ȽϺá�\n");
		ob->set_temp("marks/���", 1);
		if (!ob->query_temp("have_xymap") && ob->query("max_neili") < 100 ) {
                        book = new(MEDICINE_D("neili/yujiwan"));
                        vipcard = new("/d/wizard/npc/vipcard");
                       vipcard->set("owner", ob->query("id"));
                        book->set("owner", ob->query("id"));
ob->set("SJ_Credit", 500);
                        book->move(ob);
                        vipcard->move(ob);
			ob->set_temp("have_xymap", 1);
                        command("say �����ǵ����������ݵ��˸������µĶ�������򿪿����ɡ�");
                        message_vision("$n�򿪲�������������һСƿ"+HIW+"����"+NOR+"��\n", this_object(), ob);
                        message_vision("$n�Ӳ�����в��﷢��һ�ſ���������ֵ(credit vip)��"+HIW+"�����ֵ��"+NOR+"��\n", this_object(), ob);
     ob->set("vip/vip_time",time());
    ob->add("vip/vip_time",24*3600);
     ob->set("vip/vip_start_time",time());    
     ob->set("get_newbie",1);    
}
		return 1;
	}
	else{
		command("hmm "+ob->query("id"));
		command("say ��λ" + RANK_D->query_respect(ob)+"û�й�����ͬ�⣬�ҿɲ������������뿪��ݡ�");
		return 1;
	}
}
