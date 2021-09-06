// ����
// lane 2004.12.24 add ����

#include <ansi.h>
inherit NPC;

int ask_zhushao();
void destructing(object ob);
string ask_houshan();
string ask_me();
string ask_skill();
int ask_gold();

void create()
{
	set_name("����", ({ "su quan","su" }));
	set("long", "����ģ��������ʮ�����꣬��һ����ò�ٸ���΢΢һЦ��������̬������\n������ƥ�����������̽����ķ��ˡ�\n");
	set("gender", "Ů��");
        set("title", "�����̽�������");
        set("age", 23);
        set("str", 22);
        set("int", 32);
        set("con", 22);
        set("dex", 38);
        set("per", 50);
        set("combat_exp", 3000000);
        set("shen", -1000);
        set("attitude", "peaceful");
        set("max_qi",9000);
        set("max_jing",5000);
        set("neili",9000);
        set("max_neili",9000);
        set("jingli",1800);
        set("eff_jingli",1800);
        set("jiali",150);
        set("score", 15000);
        set("yaoli_count",1);

	set_skill("force", 250);
	set_skill("dodge", 250);
	set_skill("parry",250);
	set_skill("strike",250);
	set_skill("huagu-mianzhang", 250);
	set_skill("youlong-shenfa",250);
	set_skill("dulong-dafa",250);
	set_skill("dagger",300);
	set_skill("tenglong-bifa",300);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "youlong-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("dagger","tenglong-bifa");
	map_skill("parry","tenglong-bifa");

	set_temp("apply/damage", 88);
	set_temp("apply/dodge", 188);
	set_temp("apply/attack", 188);
	set_temp("apply/armor", 388);

	set("inquiry", ([
	//	"�ʽ�" : (: ask_gold :),
		"����" : (: ask_zhushao :),
		"zhushao" : (: ask_zhushao :),
		"�ɸ���": (: ask_houshan() :),
		"����ҩ��" : (: ask_me :),
		"��������" :(:ask_skill:),
	]) );

	set("chat_chance", 3);
	set("chat_msg", ({
		"�������������������ذ����Ȼ�������Ͼ���������������\n",
	}));

	create_family("������",1, "��������");
	setup();
	carry_object(__DIR__"obj/skirt")->wear();
	carry_object(BINGQI_D("dagger/sld_bishou"))->wield();
}

int accept_object(object me, object ob)
{
	object obj;

	if( ob->query("weapon_prop/damage") >= 80){
		obj=unew(BINGQI_D("xtbs"));
		if(obj) {
			obj->move(me);
			tell_object(me,"����������ģ�����̫���ˣ��������ذ�׾��͸���ɣ�\n");
			tell_room(environment(me), "������" + me->name() + "һ������ذ�ס�\n");
		}
		else {
			tell_object(me,"����������ģ�����̫���ˣ��������������ģ�\n");
			me->add("shen", -(3000+random(1000)));
		}
		call_out("destructing", 0, ob);
		return 1;
	}
	return 0;
}

void destructing(object ob)
{
	if(ob)
	destruct(ob);
}

int ask_zhushao()
{
	object me,ob,zs;
	mapping myfam;
	object* inv;
	int i;

	me = this_player();
	ob = this_object();
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "������") return 0;
	if(me->query("combat_exp") < 200000) {
		command("say �����ڿɲ��ܸ�������Ŷ��");
		return 1;
	}

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->query("id")=="zhushao") {
			tell_object(me,"�㲻���Ѿ���������ô��\n");
			return 1;
		}
	}

	zs = new(__DIR__"obj/zhushao");
	if (!zs)  return notify_fail("�쳣����\n");
	zs->set("owner",me);

	tell_object(me,"�ðɣ��Ҹ�������ڣ��ɲ�ҪŪ���ˡ�\n");
	tell_room(environment(me), "������" + me->name() + "һ�����ڡ�\n");
	zs->move(me);

	return 1;
}

string ask_me()
{
	object ob;
	mapping fam;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";

	if ( this_player()->query_temp("ask_slylj") )
		return "�ող��Ǹ������";
	ob=unew("/clone/book/slyaoli-book.c");

	if(!clonep(ob)) return "�������ˣ��Ǳ������Ѿ��������ˡ�";
	if(clonep(ob) && ob->violate_unique()){
		destruct(ob);
		return "�������ˣ��Ǳ������Ѿ��������ˡ�";
        }
	ob->move(this_player());
	this_player()->set_temp("ask_slylj", 1);
	message_vision("�����ӻ����ͳ�һ������ҩ���ݸ�$N��\n",this_player());
	return "�Ȿ�����Һ�½�������������ģ�����ȥ��Ҫ�ú��о�����";
}

string ask_houshan()
{
	object me=this_player();
	int lvl = (int)me->query_skill("shenlong-yaoli", 1);
	if ( lvl < 120 ) return "�ɸ�����������ңʤ��,�㻹�����ʸ�ȥ��";
	if ( file_name(environment(this_object())) != this_object()->query("startroom"))
		return "���һ���������˵�ɡ�";
	tell_object(me, "��Ȼ���ʵ��ˣ����Ҿʹ���ȥ�ɡ�\n");
	me->move("/d/sld/xfj");
	return "��һ�������ӡ�";
}
string ask_skill()
{
	object me=this_player();
	mapping myfam;
			
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "������") return 0;
	if(me->query_skill("tenglong-bifa",1)<100) return 0;
	if(me->query("sld/guifei") || me->query_skill("tenglong-bifa",1)<150)
		return "�㲻���Ѿ������������ô��";
	command("giggle");
	command("whisper "+getuid(me)+" ��ʵ�����������л��б�ľ�Ҫ֮���������������ġ�������");
	me->set("sld/guifei",1);
	tell_object(me,HIW"������������ָ�㣬��ס��ͷ�������������˹���������һ�еľ�Ҫ��\n"NOR);
	return "�����Ͼ��������ˣ������书�䲻�ع�����������ԽսԽǿ���������ҡ�";
}

int ask_gold()
{
	object me;
	int skill, gold;
	mapping myfam;
	me = this_player();
	skill = me->query_skill("dulong-dafa", 1);
	myfam = (mapping)me->query("family");

	if( !myfam || myfam["family_name"] != "������" ) {
		command("sneer "+(string)me->query("id"));
		command("say ��"+ RANK_D->query_respect(me) +"�����ú�ѽ���ǲ��ǿ����¼����ҽ̰���");
		return 1;
	}

	if( (int)me->query("sld_given") >= (int)me->query("age") ) {
		command("sigh "+(string)me->query("id"));
		command("say ����겻���Ѿ�����Ǯ�������������ɡ�");
		return 1;
	}

	if( (int)me->query("age") < 18 || skill < 50 ) {
		command("interest");
		command("say "+ RANK_D->query_respect(me) +"������ᣬ���ҽ̲��ã����ǰ���ѧ��ɡ�\n");
		return 1;
	}

	gold = 300000 + skill * 5000;
	if( 100 >= skill ) gold += gold/2;
	me->add("balance", gold);
	me->set("sld_given", (int)me->query("age"));
	command("say �ҽ̰���ʹ�ڳ�͢��Ҳ�Ǹ�����ݵ��ˣ��ʽ�Ȼ�����ѷ���");
	command("say �ҽ���" + MONEY_D->money_str(gold) + "�������Ǯׯ�����뵺���Ҫ�ú�Ϊ�ҽ̰��°���");
	return 1;
}
