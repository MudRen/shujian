// kongkong.c �տն�
// Modify By Looklove 2000/10/21

inherit NPC;
inherit F_MASTER;

int ask_book();
int ask_ji();

void consider();

void create()
{
	set_name("�տն�", ({ "kong kong","beggar","qi gai","kong" }) );
	set("title", "������ؤ");
	set("gb/bags",8);
	set("gender", "����" );
	set("age", 53);
	set("long", "һ��������˪֮ɫ������ؤ��\n");
	set("attitude", "peaceful");
        set("book_count",1);
	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("kar", 100);           // faint, so rascal! slogan

	set("qi", 800);
	set("max_qi", 800);
	set("jing", 800);
	set("max_jing", 800);
	set("eff_jingli", 800);
	set("neili", 900);
	set("max_neili", 900);
	set("jiali", 30);

	set("shen_type", 0);
//	set("apprentice",1);
        set("startroom","/d/city/lichunyuan");

	set("env/wimpy", 110);
	set("thief", 0);
	set("combat_exp", 60000);

	set_skill("force", 80);
	set_skill("strike", 75);
	set_skill("lianhua-zhang", 70);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_skill("stealing", 120);
	set_skill("begging", 100);
	set_skill("checking", 80);
	set_skill("huntian-qigong", 80);
	set_skill("xiaoyaoyou", 80);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "lianhua-zhang");
	map_skill("strike", "lianhua-zhang");

	create_family("ؤ��", 19, "�˴�����");
       	set("inquiry", ([
        	"ҽ��" : (: ask_book :),
         	"ҩ��" : (: ask_book :),
         	"�л���" : (: ask_ji :),

         ]));


	set("chat_chance", 20);
	set("chat_msg", ({
		"�տն�˵��: ���ĵĴ�ү�ġ� ����Ҫ���ļ���ͭ��ɡ�\n",
		"�տն�������ش��˸���Ƿ��\n",
		"�տն�����׽ס�����ϵ�ʭ�ӣ����: ��������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
		(: random_move :)
	}) );

	setup();

        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
        carry_object(__DIR__"obj/gb_budai8")->wear();
        carry_object("/clone/food/jitui");
        carry_object("/clone/food/jiudai");
	add_money("silver", 10);

}

void attempt_apprentice(object ob)
{
/*
	if ( ob->query("family/family_name") != "ؤ��") {
		command("say �����ؤ�����ˡ�");
		return;
	}
*/
	if ( ob->query("gb/bags") >= 2
	 && ob->query("family/family_name") != "ؤ��" ) {
                command("say ����ģ��������ͽ�������޳���С�ˣ�");
                command("say "+ob->query("name")+"�����ٷ����޳����ҵ�һ�������㣡");
                return;
        }
	command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob)+"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
        if (!ob->query("gb/bags")) ob->set("gb/bags", 1);
        command("recruit " + ob->query("id"));
        ob->set("title",sprintf("ؤ����·ֶ�%s������",
                chinese_number(ob->query("gb/bags"))) );
        ob->set("gb/fenduo","���·ֶ�");
        ob->set("class","beggar");
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	mapping fam;

	if( !ob || environment(ob) != environment()
                || ((fam = ob->query("family")) && fam["family_name"] == "ؤ��")
                || (int)ob->query("kar") > 22
                || ob->query_int() > 30
          ) return;

	switch( random(5) ) {
		case 0:
                       command("hehe " + ob->query("id"));
                       command("beg coin from " + ob->query("id"));
                       command("buy jitui");
		       break;
		case 1:
                       command("grin " + ob->query("id"));
                       command("steal silver from " + ob->query("id"));
                       command("eat jitui");
		       break;
		case 2:
                       command("hi " + ob->query("id"));
                       command("steal gold from " + ob->query("id"));
                       command("drink jiudai");
		       break;
		case 3:
                       command("pat " + ob->query("id"));
                       command("beg jiudai from " + ob->query("id"));
                       command("eat jitui");
		       break;
		case 4:
                       command("walkby " + ob->query("id"));
                       command("beg jitui from " + ob->query("id"));
                       command("drink jiudai");
		       break;
	}
}


int accept_object(object me, object obj)
{
      	object ob,ob1;
      	ob=this_player();

      	if (obj->query("money_id") && obj->value() <= 100000) {
        	 command("smile");
	         command("say ��л�� ! ��ʵ�һ����е�Ǯ�ģ����ֻ������������� !");
        	 command("give 10 silver to " + me->query("id"));
	}
       	else if (ob->query_temp("marks/��ʾ")&&(query("book_count") >= 1)&&(
	obj->id("kao ya") || obj->query("id") == "lingbai xiaren" ||
	obj->query("id") == "dongsun-tang"|| obj->query("id") == "yingtao huotui")) {
		command("nod");
		command("say ����ô�������Ȿ�������ȥ��.");
		ob1 = new("/clone/medicine/m-book4");
		ob1->move(this_player());
		ob->delete_temp("marks/��ʾ");
		add("book_count", -1);
	}
	else if ( ob->query_temp("marks/find-ji",1) ) {
		if (( !obj->query("money_id") && obj->query("value",1) >= 100000 )
		 ||( obj->query("money_id") && obj->value() >= 100000 )) {
			command("hehe");
			command("say ����ô��������ֻ�������ȥ��.");
			ob1 = new(__DIR__"obj/jiaohuaji");
			ob1->move(this_player());
			ob->delete_temp("marks/find-ji");
			call_out("destroying", 1, obj);
		}
		else {
			command("sigh kong");
			return 1;
		}
	}
	else {
		command("shake");
		command("say ���ֶ������Ҫ ! ��һ��ȥ !");
		return notify_fail("");
	}
	return 1;
}

void destroying(object obj)
{
        if (obj)
	destruct(obj);
        return;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "����С������뿪\n");
	return 0;
}

int ask_book()
{
  	object ob;
  	ob=this_player();
	if (ob->query_temp("marks/m-book4"))
	{
		command("xixi");
		command("say ��������˵�Ǳ��鰡��������������������Һ��󲻼ǵ÷�����?\n"
		+RANK_D->query_respect(ob)+"�ǲ��ǵ�����...�ĸ���ʾ..��ʾ...��\n");
  		ob->delete_temp("marks/m-book4");
  		ob->set_temp("marks/��ʾ",1);
		return 1;
	}
	else {
		command("?");
	command("say ��˵ʲô�����Ҳ���,�ɱ�ԩ������!\n");
	return 1;
	}
}

int ask_ji()
{
        object ob;
  	ob=this_player();

  	if (ob->query_temp("marks/lost-ji",1)) {
                if ( random(10 ) < 2){
         		command("?");
         		command("say ��˵ʲô�����Ҳ���,�ɱ�ԩ������!\n");
          	} else {
			command("say ��������˵��ֻ������������������������Һ��󲻼ǵ÷�����?\n" +RANK_D->query_respect(ob)+"�ǲ��ǵ�����...�Ǹ���ʾ..��ʾ...��\n");
  			ob->delete_temp("marks/lost-ji",1);
  			ob->set_temp("marks/find-ji",1);
		}
	} else {
   		command("dunno");
        }
	return 1;
}
