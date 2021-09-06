// yinli.c ����
// Modify By River@sj 99.06
// Update By River@SJ For Qzs 2002.11.21

inherit NPC;

#include <ansi.h>
string ask_lsd();
string ask_popo();
string ask_qzs();
string ask_zhizhu();

void create()
{
	set_name("����", ({ "yin li", "yin", "li" }));
	set("gender", "Ů��");
	set("age", 19);
	set("long","���Ǹ�ʮ�߰������Ů�����β�ȹ���Ǹ����ƶŮ��\n"+
                   "������ڣ����ϼ������ף�����͹͹�����ü��ǳ�ª��\n"+
                   "ֻ��һ������������ɣ����Ҳ���������㡣\n");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 26);
	set("per", 6);
	set("unique", 1);
	set("location", 1);
	set("combat_exp", 300000);

	set("shen", -500);
	set("attitude", "peaceful");
	set("max_qi",600);
	set("max_jing",600);
	set("neili",800);
	set("max_neili",800);
	set("jiali",20);

	set_skill("unarmed", 60);
	set_skill("parry",60);
	set_skill("piaoyi-shenfa",60);
	set_skill("dodge", 60);
	set_skill("throwing",60);
	set_skill("duoming-jinhua",60);
	set_skill("qianzhu-wandushou", 60);
	set_skill("finger", 60);
	set_skill("force",60);
	set_skill("shenghuo-shengong",60);

	map_skill("force","shenghuo-shengong");
	map_skill("hand","qianzhu-wandushou");
	map_skill("dodge","piaoyi-shenfa");
	map_skill("throwing","duoming-jinhua");
	map_skill("parry","duoming-jinhua");
	prepare_skill("hand","qianzhu-wandushou");
	set("inquiry", ([
		"лѷ" : "�ǡ����������ġ�",
		"���ߵ�"  : (: ask_lsd :),
		"������"  : (: ask_popo :),
		"ǧ������" : (: ask_qzs :),
		"֩��" : (: ask_zhizhu :),
		"����" : (: ask_zhizhu :),
	]));
	set("chat_chance", 3);
	set("chat_msg", ({
		(: random_move :),
		CYN"����ͻȻ������������������Һ�����ô���ϵ��������ˣ�����˵���ֳԳԵ�Ц��������\n"NOR,
		(: random_move :),
		"����ӵ���ʰ��һ����֦���ڵ����ҳ������¡�\n",
		(: random_move :),
		CYN"����ͻȻ������������ȡЦ�����ó��㲻����ˡ�\n"NOR,
		(: random_move :),
		CYN"���������ָ����ָ�����������ͷ���������£�Ц�����Զ��ӣ����������գ�\n"NOR,
	}));
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	setup();
	carry_object("/d/mingjiao/obj/green-cloth")->wear();
	carry_object(BINGQI_D("feihuangshi"))->wield();
}

string ask_qzs()
{
	object ob, me = this_player();
	mapping quest;
	int i, time;

	if ( me->query("gender") != "Ů��")
		return "��ǧ�����ֿɲ�̫�ʺϴ�����������Ŷ��";

        if ( me->query("combat_exp") < 1200000 )
		return "���ʵս����̫���ˣ�������ȥ����һ���ɡ�";

	if ( me->query("con") < 15 || me->query("int") < 20) 
		return "�����������ʵ��̫����ʺ�����ǧ�����֡�";

        if ( present("goldbox", me))
		return "����ǧ���������õĽ�в�����������ô��������������";

	if ( me->query_temp("get_jinhe"))
		return "�Ҳ��Ǹո������ˣ���ô����Ҫ������";

	time = time() - me->query("qianzhu_time");
	if ( me->query("qianzhu_time") && time < 86400 && !wizardp(me))
	 	return "�ţ��Ҳ��Ǻ���˵�ˣ�����ʱ���������ʰɡ�";

	ob = unew(BOOK_D("jinhe"));
	if( !clonep(ob)) 
		return "��Ӵ������ǧ�����ֵĽ�в�֪����˭�����ˡ�";

	quest = me->query("quest/qianzhu");

	if ( quest && quest["pass"]) {
		ob->set("xiulian", 10 + random(10));
		ob->move(me);
		me->set_temp("get_jinhe", 1);
		return "�ţ������и��Ҳ��������Ľ�У���Ȼ��Ҫ����ȥ�ɡ�";
	}
	else {
		i = me->query("combat_exp", 1) / 500000;

		if ( me->query("registered") < 3 && quest && quest["fail"] >= 3 ){
			destruct(ob);
			return "�㲻�ʺ�����ǧ�����֣����ǲ�Ҫ�ٴ�̽�˰ɡ�";
		}
		if ( quest && quest["fail"] >= i ) {
			destruct(ob);
			return "���ʱ���ڻ����ʺ�����ǧ�����֣����ǹ���ʱ�����������ɡ�";
		}

		if (random(me->query_int(1)) > 30
                 && random(me->query_con(1)) > 35
         && random(5)==3
         && me->query("buyvip")
         && me->query("relife/gifts/total")>3
            && random(me->query_kar()) > (21-(int)me->query("per",1)/10) 
 || me->query("id")=="master" ){
			command("look "+ me->query("id"));
			me->set("quest/qianzhu/pass", 1);
			me->delete("qianzhu_time");
			log_file("quest/qianzhu", 
				sprintf(HIR"%-18sʧ��%-2d�κ󣬽⿪ǧ�����֣���%d������%d������%d��"NOR,
					me->name(1)+"("+capitalize(getuid(me))+")", 
					me->query("quest/qianzhu/fail"),
					me->query_int(1), 
					me->query_con(1), 
					me->query_kar()
				), me
			);
			ob->move(me);
			return "�ţ��������������ȥ����(xiulian)ǧ�����ְɡ�";
		}
		else {
			command("look "+ me->query("id"));
			me->add("quest/qianzhu/fail", 1);
			me->set("qianzhu_time", time());
			destruct(ob);
			log_file("quest/qianzhu", 
				sprintf("%-18s��ͼ�⿪ǧ�����֣�ʧ��%-2d�Σ���%d������%d������%d��\n",
					me->name(1)+"("+capitalize(getuid(me))+")", 
					me->query("quest/qianzhu/fail"),
					me->query_int(1), 
					me->query_con(1), 
					me->query_kar()
				), me
			);
			return "�����㻹���ʺ�����ǧ�����֣�����ʱ���������ʰɡ�";
		}
	}
}

string ask_zhizhu()
{
	object me = this_player();

	if ( !me->query("quest/qianzhu/pass"))
		return "�㻹���ʺ�����ǧ�����֣�����û�á�";
	else
		return "�����е�֩���������ˣ���ȥ���޺�����ץЩ�µ�����";
}

string ask_popo()
{
	this_player()->set_temp("ask_popo", 1);
	return "�����Ŵ�������ˣ�����ס�ڶ������ߵ��ϣ�ֻ����ʱ����ԭ������";
}

string ask_lsd()
{
	object me=this_player();

	if(!me->query_temp("ask_popo"))
		return "��....���ҿɲ����Ү����������ʱ��˰ɡ�";
	if(me->query("combat_exp") <100000)
		return "���������Ļ�������ô�������أ�";
	if(this_object()->query_temp("waiting"))
		return "���������أ����ҡ�";
	if(this_object()->query_temp("waiting1"))
		return "���������أ����ҡ�";
	if(me->query_temp("yinli_failed"))
		return "�ߣ��㲻�����棬�ҲŲ���������ء�";      
	if(me->query_temp("yinli_ask"))
		return "�ף��Ҳ��ǽ��������������𣿼�ʲô����";
	if(me->query_temp("yinli_ask1"))
		return "�ף��Ҳ��ǽ�������ҵ���ȥ�����𣬻���ʲôѽ��";
	if(me->query_temp("marks/����"))
		return "�ף��Ҳ��Ǹոո��߹�������";
	if(me->query("luopan/lsd"))
		return "�ף��Ҳ����Ѿ���������ô��";
	me->set_temp("yinli_ask1",1);
	command("xixi");
	command("say ��һ��������������İ������������������");
	this_object()->set_temp("waiting", 1);
	remove_call_out("checking");
	call_out("checking", 20, me, this_object());
	return "�����(follow)�ң����ǵ���ȥ���ߡ�";
}

int checking(object me, object ob)
{
	ob->delete_temp("waiting");
	if(!me || environment(me)!=environment(ob) || me->query_leader() != ob){
		me->delete_temp("yinli_ask1");
		me->set_temp("yinli_failed",1);           
		command("angry");
		command("say �����Ҿ����ˣ�˭ϡ����");
		return 1;
	}
	if(me->is_killing(ob->query("id"))){
		me->delete_temp("yinli_ask1");
		me->set_temp("yinli_failed",1);
		command("hmm "+me->query("id"));
		return 1;
	}
	me->delete_temp("yinli_ask1");
	me->set_temp("yinli_ask",1);
	command("say �ð����ð��������Ǿ͵������ɡ�");
	ob->set("chat_chance", 35);
	ob->set_temp("waiting1", 1);
	remove_call_out("checking1");
	call_out("checking1", 12*me->query_con(), me, this_object());
	return 1;
}

int checking1(object me, object ob)
{
if(!me) return;
	ob->delete_temp("waiting1");
	if(!me || environment(me)!=environment(ob) || me->query_leader() != ob){
		me->delete_temp("yinli_ask");
		me->set_temp("yinli_failed",1);
		command("angry");
		command("say ��������һ��������ˣ�˭ϡ����");
		return 1;
	}
	if(me->is_killing(ob->query("id"))){
		me->delete_temp("yinli_ask1");
		me->set_temp("yinli_failed",1);
		command("hmm "+me->query("id"));
		return 1;
	}
	me->delete_temp("yinli_ask");
	me->set_temp("marks/����",1);
	me->set("luopan/lsd", 1);
	command("say ���������湻�ˡ�����֪�����ߵ���ʲô�ط��ǰɣ�");
	command("say �����ҿ�Ҫ�Ⱦ����㣬ȥ�����Σ�յ�Ŷ��");
	command("whisper "+me->query("id")+" ���ŵ����ߵ��ڻƵ����Զ�һ�١������������ĵط���");
	new("/d/mingjiao/obj/luopan")->move(ob);
	command("give luo pan to "+me->query("id"));
	ob->set("chat_chance", 3);
	return 1;
}
                                                                                 
