// lucf.c
// By jpei
// �������bai lu guanying��code Modified by Numa 19990917
// Modified by Darken for taohua quest
// Modified by mxzhao 2004/05/12 for shen restrict to exp/10

#include "nadir.c"
#include <ansi.h>
inherit NPC;

int ask_ci();
int ask_yue();
string ask_book();
string ask_quest();

void create()
{
	set_name("½�˷�", ({"lu chengfeng", "lu", "chengfeng"}) );
	set("title", "����ׯׯ��");
	set("nickname", HIR"�������"NOR);
	set("long", "����ɫ���ݣ�������ߣ��������һ���������ƺ�˫���вм���\n");
	set("gender", "����" );
	set("age", 42);
	set("attitude", "friendly");
	
	set("str",30);
	set("int",29);
	set("con",28);
	set("dex",5);
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("eff_jingli", 2000);
	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 60);
	set("combat_exp", 800000);
	
	set_skill("force", 140);
	set_skill("bihai-chaosheng", 130);
	set_skill("qimen-baguazhen",100);
	set_skill("dodge", 130);
	set_skill("suibo-zhuliu", 130);
	set_skill("parry", 140);
	set_skill("strike", 140);
	set_skill("luoying-zhang", 130);
	set_skill("leg", 140);
	set_skill("xuanfeng-tui", 130);
	set_skill("sword", 130);
	set_skill("yuxiao-jian", 130);
	set_skill("taoism", 120);
	set_skill("literate", 100);
	set_skill("qimen-bagua", 140);
	
	map_skill("force", "bihai-chaosheng");
	map_skill("dodge", "suibo-zhuliu");
	map_skill("strike", "luoying-zhang");
	map_skill("leg", "xuanfeng-tui");
	map_skill("parry", "yuxiao-jian");
	map_skill("sword", "yuxiao-jian");
	prepare_skill("strike", "luoying-zhang");
	//	prepare_skill("leg", "xuanfeng-tui");
	
	set("rank_info/respect", "ׯ��");
	set("shen_type", 1);
	set("shen", 100);
	//	set("vendetta_mark", "�һ���");
	
	create_family("�һ���", 2, "����");
	set("class", "fighter");
	
	set("inquiry", ([
		"rumors": "�ܾ�û����ʦ�ֵ���Ϣ�ˣ���֪���Ƿ�������⣿",
		"here": "�����ǹ���ׯ�������תת�ɣ������뵽�ͷ���Ϣ��",
		"��" : "������ϵĴ���һλ��Ӣ�ۡ������������",
		"��" : (: ask_ci :),
		"��" : "�����������д�ģ��㿴��ô����",
		"��Ӣ��": "���ȿ�������˵���ѵ���û�ж������״���",
		"�����": "���ȿ�������˵���ѵ���û�ж������״���",
		"����" : (: ask_yue :),
		"������" : (: ask_yue :),
		"��а": "���Ƕ�ʦѽ����Ȼ��������ǵ�˫�ȣ��������ǳ�������һ��Ϊʦ������Ϊ��ѽ��",
		"��ҩʦ": "���Ƕ�ʦѽ����Ȼ��������ǵ�˫�ȣ��������ǳ�������һ��Ϊʦ������Ϊ��ѽ��",
		"��ʦ" : "�����һ�������ҩʦ�ˣ��������������Ĳ���ѧ���黭���壬������ԣ�ҽ�����࣬�������У���һ������",
		"��ʦ" : "�����һ�������ҩʦ�ˣ��������������Ĳ���ѧ���黭���壬������ԣ�ҽ�����࣬�������У���һ������",
		"����": "�ţ�����Сʦ�ã��Ǽ�ʦ���������顣",
		"����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"�һ���": "�û���ԭ������������ʱ��ѽ����ʦ�����뵺ʱ�����˺�ͼ�ء�",
		"½��Ӣ": "����СȮ����ǰ�����ɶ�������ϰ�գ�����ʦ����׼��������ѧ���ˡ�",
		"����ׯ": "�����ǻ�����������Ѫ�Ž������ģ�����ׯԺ�����Σ�",
		"�׾�": (: ask_book :),
		"����ͷ": (: ask_quest :),
        ]) );
	
	set("chat_chance", 3);
	set("chat_msg",({
		"½�˷�����Ƿ�����̾һ����ĬȻ��������������¡�\n",
	}));
	setup();
	
	carry_object("/d/city/npc/obj/xiao.c")->wield();
	carry_object(__THD__"obj/grn-cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	object letter;
	string letter_desc;
	
	if (!ob->query("family") || ob->query("family/family_name")!= "�һ���"){
		command("say "+RANK_D->query_respect(ob)+"�书����̫������ȸ�С����Ӣѧѧ�ɣ�");
		return;
	}
	if ((int)ob->query_skill("bihai-chaosheng", 1) < 80){
		command("say ���һ���һ���书��̥�ڵ��̣��������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ���ڱ̺��������϶��µ㹦��");
		return;
	}
	if ((int)ob->query("family/generation")==2){
		command("say "+RANK_D->query_respect(ob)+"�Ѿ����һ����ڶ������ӣ�������������Ϊͽ��");
		return;
	}
	if (!ob->query("thd/receive"))
	{
		command("say û�м�ʦ�����½ĳ�������Խ���ʦ���书ת�����ˣ�");
		if (ABS(ob->query("shen")) < 200000
			&&  ob->query_int() >= 28){
			command("say �����ҿ�" + RANK_D->query_respect(ob) + "�����ʻ����������ɣ���дһ���Ƽ��ţ�����ȥ�Ҽ�ʦ�ɡ�");
			letter = new(__GUI__"obj/tuijian_xin");
			letter->set("owner", ob->query("id"));
			letter_desc = "����½�˷�д����ҩʦ��һ���ţ�����д�ţ�\n��ʦ���ϣ�����" + ob->query("name") + "һ���������뱾�ɣ����Ӳ�����ר�����������ʲ����ش��Ƽ����ʦ���ᡣ  �˷�ߵ��\n";
			letter->set("long", letter_desc);
			letter->move(ob);
			message_vision("½�˷��ͳ�һ���Ƽ��ţ�д��$N�����֣�������$N��\n", ob);
			command("say ��ʦ���һ�������ҩʦ������Ҫ���ٰ����������ϵ��������һ�����λ�������...��...�������뿴...");
			command("consider");
			command("doubt chengfeng");
			command("sigh");
			command("say ��Ȼ�벻�����ˣ���ȥ����ʦ�������ɣ������ٰ����ϵ�ţ�Ҵ忪��һ��С�ꡣ");
		}
		return;
	}
	ob->delete("thd/receive");
	if (ob->query("gender") != "����" && ob->query("gender") != "Ů��") {
		command("say �㲻�в�Ů����ʲô�����������");
		return;
	}
	if (ob->query("shen") < -ob->query("combat_exp")/10 
		&& (int)ob->query("shen") < -200000) 
	{
		command("say ��ʦ��ƽ�����������ˣ����������޶�����аħ���������һ����ȥ���ʦ�ɣ�");
		return;
	}
	if (ob->query("shen") > ob->query("combat_exp")/10 
		&& (int)ob->query("shen") > 200000) 
	{
		command("say ��ʦ��ƽ�����������ˣ������������������Ĺ�������֮ͽ������һ����ȥ���ʦ�ɣ�");
		return;
	}
	if (ob->query("class") == "bonze") {
		command("say ��ʦ�Ƚ��������ֺ��У��ҿɲ����������㡣��ȥ���ʦ�ɣ�");
		return;
	}
	command("say ��Ȼ��ʦ����Ҿ�����Ϊͽ�ɡ�");
	command("recruit " + ob->query("id"));
	ob->set("class", "fighter");
	ob->set("title","�һ�������������");
}


void init()
{
	add_action("do_answer","answer");
	add_action("do_answer","huida");
	add_action("do_kill","kill");
}

int do_kill(string arg)
{
	object ob;
	object me = this_player();
	
	if (!arg) return 0;
	ob = present(arg, environment(me));
	if (ob == this_object() || ob == me) return 0;
	if (!ob || !ob->is_character()) return 0;
	if (ob->query("family/family_name") == "�һ���") {
		if (me->query("family/family_name") == "�һ���") {
			message_vision("½�˷���$N�ȵ���Сū�ţ�Ҫ�췴�����Լ���ͬ�Ŷ�ɱ����\n", me);
		}
		else {
			message_vision("½�˷���$N�ȵ����󵨿�ͽ������������ׯ��Ұ����\n", me);
			message_vision("½�˷��$N˵���������ÿ�����������ʰ���" + RANK_D->query_rude(me) + "��\n", ob);
			kill_ob(me);
		}
		me->set("vendetta/�һ���", 1);
		return 1;
	}
	return 0;
}

int ask_ci()
{
	object ob = this_player();
	
	command("say д���״ʵĴ�Ӣ�ۡ�����ܾ��������¡�\n");
	if(!ob->query_temp("guiyun_lutemp"))
		ob->set_temp("guiyun_lutemp", 1);
	return 1;
}

int ask_yue()
{
	object ob = this_player();
	
	if(ob->query_temp("guiyun_lutemp") >= 1) {
		command("say ��ϧ�ҵ�������һ����������ԭ�ⲻ̫�������֪" + RANK_D->query_respect(ob) + "�ܷ񿴳�����\n");
		ob->set_temp("guiyun_lutemp", 2);
	}
	else {
		command("say ���������ҷǳ����ص�һλ��Ӣ�ۡ�\n");
	}
	return 1;
}

int do_answer(string arg)
{
	object ob = this_player();
	
	if (ob->query_temp("guiyun_lutemp") == 2) {
		tell_room(environment(ob), ob->name() + "����½�˷�٩٩��̸��\n", ({ob}));
		if (arg == "֪����,�Ҷ���˭��?" || arg == "֪���٣��Ҷ���˭����"
			|| arg == "֪����,�Ҷ���˭��" || arg == "֪���٣��Ҷ���˭��") {
			if (!present("tuifa tujie", ob) && query_temp("tuifa_give") < 5) {
				say("½�˷糤��һ�������ⷬ���飬���ղű��㿴�ƣ���νƽ��һ֪�ѣ��Ȿ�ȷ����͸���ɡ�\n");
				new(__GUI__"obj/tuifa.c")->move(ob);
				ob->delete_temp("guiyun_lutemp");
				add_temp("tuifa_give",1);
			}
			else {
				say("½�˷糤��һ�������ⷬ���飬���ղű��㿴�ƣ���νƽ��һ֪�ѣ�ֻ��ϧ�Ϸ���û��ʲô���������ġ�\n");
			}
		}
		else {
			command("? " + ob->query("id"));
			message_vision("½�˷��ɻ�ؿ���$N��" + RANK_D->query_respect(ob) + "�ƺ�Ӧ�ö�ѧЩ�鷨�滭�ɣ�\n", ob);
		}
		return 1;
	}
	return 0;
}

string ask_book()
{
	mapping fam;
	object ob;
	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "�һ���")
        return RANK_D->query_respect(this_player()) +
		"���Ǳ��ɵ��ӣ�Ҫ�����������ã�";
	ob = unew("/d/baituo/obj/book5");
	if(!clonep(ob))
		return "�������ˣ��Ȿ���������ʮ���Ե����鲻�ڴ˴���";
	if(clonep(ob) && ob->violate_unique()){
		destruct(ob);
		return "�������ˣ��Ȿ���������ʮ���Ե����鲻�ڴ˴���";
	}
	ob->move(this_player());
	return "�ðɣ��Ȿ���׾������û�ȥ�ú����С�";
}

string ask_quest()
{
	mapping fam;
	object obj;
	
	object me = this_player();
	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "�һ���")
		return RANK_D->query_respect(this_player()) +
		"���Ǳ��ɵ��ӣ����ǿ��뿪�ĺá�";
	if (me->query_temp("thd/onquest")!=5)
		return RANK_D->query_respect(me) + "�Ͻ��뿪�˵ذɣ�������ˡ�";
	command("say ��Ӣ�Ѿ��������ˣ�");
	command("sigh");
	command("say ������÷ʦ�������ģ��㻹�ǿ�Щ�뿪������......\n\n");
	message_vision(HIY"ͻȻ��Ӱ�ζ���һ�˽е���÷ʦ�������ڴˣ���\n", me);
	message_vision(HIY"����½�˷繥ȥ���㡰�����ľ���һ��������÷����\n", me);
	message_vision(HIY"һ��������ת�����㹥����\n\n"NOR, me);
	message_vision(HIR"÷����е�����ɱ���������ӵ�С��������Ҫȡ�㹷����\n"NOR, me);
	obj = new("/d/lanzhou/npc/mei");
	obj->set_temp("target",me->query("id"));
	obj->move(environment(me));
	me->start_busy(random(2)+1);
	me->set_temp("thd/onquest",6);
}

