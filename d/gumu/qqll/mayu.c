// mayu.c ����
// kxkxkx 2004��3��
// Rewrite By Ciwei@SJ

#include <ansi.h>
#include <get_place.h>


#define QQLL_OB "/d/gumu/qqll/qqll"
#define QQLLYU_OB "/d/gumu/qqll/qqllyu"

#define MIN_EXP 1000000
#define MIN_EXP_DIFF 1000000

inherit NPC;

#include <mudlib.h>

private nomask int ask_qqll();

private nomask int ask_job();
private nomask int can_ask_job();

private nomask void assign_job();
private nomask string set_cyl_location(object obj);
private nomask object set_cyl_player(object obj,object pal);

private nomask int ask_fangqi();

private nomask int ask_ok();
private nomask void give_prize();

int ask_gift()
{
	object me = this_player();
	
	if(INTERMUD_MUD_NAME!="TEST") return 0;
	
	me->set_skill("duanzao",230);
	me->set_skill("zhizao",230);
	
	WORKER_D->check_impove(me,"duanzao",999999,3);
	WORKER_D->check_impove(me,"zhizao",999999,3);
}

void create()
{
   set_name("����", ({"ma yu", "ma"}));
   set("title", HIR"ȫ���ƽ�"NOR);
   set("nickname", HIR"������"NOR);
   set("gender", "����");
   set("age", 35);
   set("long",
      "һ���ɷ���ǵ�������ˡ�\n"
      "��̬���飬��ֹ���ݣ�һ������������ˡ�\n");
   set("attitude", "friendly");
   set("shen", 10000);
   set("str", 20);
   set("int", 20);
   set("con", 20);
   set("dex", 20);
   set("per", 30);
   
   //set("unique", 1);
   
   set("no_get", "���ڶ������̫���ˡ�");
   set("combat_exp", 3000000);
   set("max_neili", 2000);
   set("neili", 2000);
   set("jiali", 50);
   
   set_skill("force", 300);
   set_skill("sword", 300);
   set_skill("cuff", 300);
   set_skill("dodge", 300);
   set_skill("parry", 300);
   set_skill("xiantian-gong", 300);
   set_skill("taizu-quan", 300);
   set_skill("quanzhen-jianfa", 300);
   set_skill("jinyan-gong", 300);
   
   set("no_ansuan",1);
   set("job_npc",1);
      
   map_skill("sword", "quanzhen-jianfa");
   map_skill("parry", "quanzhen-jianfa");
   map_skill("dodge", "jinyan-gong");
   map_skill("force", "xiantian-gong");
   map_skill("cuff", "taizu-quan");
   prepare_skill("cuff", "taizu-quan");
   
   create_family("ȫ���", 2, "����");
   
   set("inquiry", ([
      "������" : "���������ǽ����񽳣�",
      "����ʯ" : (:ask_qqll:),
      "job" : (:ask_job:),
      "fangqi" : (:ask_fangqi:),
      "����" : (:ask_fangqi:),
      "ʧ��" : (:ask_fangqi:),
      "���" : (:ask_ok:),
      "finish" : (:ask_ok:),
      
//      "gift":(:ask_gift:),///������
            
      ]));
      
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.qixing" :),
	}));	


   setup();

   carry_object(ARMOR_D("caoxie"))->wear();
   carry_object(ARMOR_D("blackrobe.c"))->wear();
   carry_object(BINGQI_D("changjian"))->wield();
}

// ����������
private nomask int ask_qqll()
{
   command("say ��ʦ�����������˸�һ�����"
      "�����ҵ���һ�����С�" HIG"����ʯ"NOR "������ʯ��");
   command("say ��һֱ��Ѱ���ܹ����ҽ⿪��ʦ����֮�ܹ��ɽ���");
   
   this_player()->set_temp("qiyanjob_ask",1);
   return 1;
}

// Ҫ������������
private nomask int ask_job()
{
	if(can_ask_job())
      assign_job();  // ����Ҫ������������
	return 1;
}

// �ж��Ƿ����Ҫ������������
private nomask int can_ask_job()
{
   object user, pal, *team;
   int user_exp, pal_exp;

   user = this_user();
   user_exp = user->query("combat_exp");
   
   if(!user->query_temp("qiyanjob_ask"))
   {
   	return 0;
   }      
   if(present("qiyan shi",user))
   {
   	command("say �㲻���Ѿ�����������ô��");
   	return 0;
   }
   
   if(user_exp < MIN_EXP) {
      command("say ���¹�ϵ����ʦ�����ͬС�ɡ�" +
      RANK_D->query_respect(user) +
      "�����Ϊ���������ǲ�Ҫ�����˰ɡ�");
      return 0;
   }
   if(!user->is_team_leader()) {
      message_vision("$N���´�����$n���ۡ�\n", this_object(), user);
      command("say ǰ·ãã��" + RANK_D->query_respect(user) +
         "����һ��ǰ����׳־�ɼΣ���ƶ��ȴ���ܷ��İ���");
      return 0;
   }
   team = user->query_team();
   if(sizeof(team) > 2) {
      command("say ��һ������ˣ�˭֪�����Ǵ�ٵĻ��Ǹ���ģ�");
      command("nonsense");
      return 0;
   }
   pal = team[1];
   pal_exp = pal->query("combat_exp");
   if(pal_exp - user_exp <= MIN_EXP_DIFF) {
      command("say �������Ļ�����ֲ��а�����һ�����£�"
         "��ʱ���������㻹�����������");
      return 0;
   }
   if(pal_exp - user_exp >= MIN_EXP_DIFF*4 )
   {
   	command("say �������Ļ���ǽ������˰����㲻Ҫ���Ǵ������³����ò��á���");
   	command("disapp "+user->query("id"));
   	return 0;
   }
   //
   if(!present(pal)) {
      command("say �ף���ô�����˲�ȫ����" + pal->query("name") +
         "��ôû����");
      return 0;
   }
   if(user->query_condition("job_busy") ||
         pal->query_condition("job_busy")) {
         command("say ����������ôæ�������鷳�����ˡ�");
      return 0;
   }
   if(user->query("job_name") == "��������" ||
         pal->query("job_name") == "��������") {
      command("say ����û��������Ҫ�鷳���ǡ�");
      return 0;
   }
   if(user->query_skill("duanzao",1) < 220 && user->query_skill("zhizao",1) < 220
   && user->query_skill("caikuang",1) < 220 && user->query_skill("nongsang",1) < 220)
   {
   	message_vision(CYN"$N���´�����$n���ۡ�\n"NOR,this_object(),user);
   	command("say �ҿ����Լ�����������ʯ�����˽ⲻ�࣬����զ��ʲôѽ��!");   	
   	return 0;
   }      
   // ok
   return 1;
}


private nomask void assign_job()
{
   object user, pal, qqll;
   //string s_area_n;
   int job_busy, r, max_killers;
   
   object s_player;
   
   user = this_user();   
   pal = (user->query_team())[1];      
   //s_area_n = set_cyl_location(qqll);
   qqll = new(QQLL_OB);
   qqll->set("pal", pal);
   s_player = set_cyl_player(qqll,pal);
   	if(!s_player)
   	{
   		destruct(qqll);
   		command("say");
   		return;
   	}
   	
	user->delete_temp("qiyanjob_ask");
	job_busy = random(10) + 35; // need modifying it?
	
	job_busy = job_busy/3;
	
	user->apply_condition("job_busy", job_busy);
	pal->apply_condition("job_busy", job_busy);
	
	if(user->query("combat_exp")<5000000) r = random(30);
	else if(user->query("combat_exp")<10000000) r = random(20);
	else r = random(15);
	
	max_killers = r < 1 ? 5 : (r < 5 ? 3 : 4);
	
	//max_killers = 5;
	qqll->set("killers", 0);
	qqll->set("max_killers", max_killers);
	command("say ��Ȼ��ˣ����鷳" + RANK_D->query_respect(user) +
	"�����ｻ�� ������ ��������");
	command("whisper " + user->query("id") + " �����������ײ���β���ϴ�"+s_player->query("name")+"("+s_player->query("id")+")"+"����" + get_place( base_name(environment(s_player)) ) + "���������ټ��������ȥ����������");
	message_vision("$N��$nһ" + qqll->query("unit") + qqll->name() + "��\n", this_object(), user);
	qqll->move(user);
}

private nomask object set_cyl_player(object qqll,object pal)
{
	object* all = users();
	object target;
	int i,j;
	string place;
	
	if(!qqll) return 0;
			
	for(i=0;i<sizeof(all);i++)
	{
		j = random(sizeof(all));		
		target = all[j];
				
		if(!objectp(target)
		|| !environment(target)
		|| !living(target)
		|| !interactive(target)
		|| query_idle(target) > 600
		|| getuid(target) == getuid(pal)
		|| getuid(target) == getuid(this_player())
		|| wizardp(target)
		|| target->query("combat_exp") < 10000		
		|| target->is_ghost()
		|| !place = base_name(environment(target))
		|| strsrch(place,"/d/")!=0
		|| strsrch(place,"/d/death")==0
		|| strsrch(place,"/d/wizard")==0
		|| strsrch(place,"/d/wuguan")==0		
		|| time() - target->query_temp("qqll_job_be_ask") < 7200
		|| !userp(target) )
		{
			target = 0;
			continue;			
		}
		break;		
	}
			
	if(!target) return 0;

	target->set_temp("qqll_job_be_ask",time());
	qqll->set("target_player",target->query("id") );
	place = base_name(environment(target));
	place = place[3..<1];
	place = place[0..strsrch(place,"/")-1];
	place = "/d/"+place;
	qqll->set("target_place",place);
			
	return target;
}

private nomask int ask_fangqi()
{
   object user, qqll, pal;
   
   user = this_user();
   qqll = present("qiyan stone", user);
   if(!qqll) {
      command("say ������û�����������ʲô��");
      return 1;
   }
   command("say ��ʦ���µ��������ⲻ���ˣ�");
   message_vision("$N��$nʧ�����ˡ�\n", this_object(), user);
   command("say �����æ�������ҵĴ�");
   message_vision("$N��$n�����û�" + qqll->query("name") + "��\n",
      this_object(), user, qqll);
   user->apply_condition("job_busy", 10);
   pal = qqll->query("pal", 1);
   if(pal) pal->apply_condition("job_busy", 10);
   destruct(qqll);
   return 1;
}

private nomask int ask_ok()
{
   object user, qqll, qqllyu,pal;
   int ok;
   
   user = this_user();
   qqll = present("qiyan stone", user);
   if(!qqll) {
      command("say �㻹û�������أ���ô��ɣ�\n");
      return 1;
   }
   ok = qqll->query("ok");
   pal = qqll->query("pal", 1);
   if(!ok) {
      command("say �㻹û����������ء�\n");
      return 1;
   }
   
   if( (!pal || !present(pal) ) && !wizardp(user) )
   {
   	command("say ���ͬ���أ�");
   	return 1;
   }
   
   switch(ok) {
      case 1:
         command("say ��ҡײƭ֮ͽ��������������˵���Լ��ɡ�");
         break;
      case 2:
         command("say ԭ����ˣ����������񡭡�����л׳ʿ��"
            "ƶ���Ե��ٲ�����ʦ��ѵ��");
           give_prize();
         break;
      default:
         qqllyu = new(QQLLYU_OB);
         say("���ڳ�̾һ��������ʯһ�����������磬�������ϣ�"
            "�������š���\n");
         command("say ��л׳ʿ���⿪ƶ������֮���ᡣƶ�����Իر���"
            "�������������׳ʿ�ɡ�");
         message_vision("$N��$nһ��" + qqllyu->query("name") +
            "��\n", this_object(), user);
         qqllyu->move(user);
         give_prize();
         break;
   }
   
   if(ok==1)
   {
   	int exp = 100 + random(100);
   	int pot = exp / 5 + random(exp / 6);
   	
   	user->add("potential", pot);
   	if(user->query("potential") > user->query("max_pot"))
   		user->set("potential", user->query("max_pot"));
   	
   	user->add_exp_combat(exp,this_object(),"��������");
   	//user->add("combat_exp",exp);
   	pal = qqll->query("pal", 1);
   	if(pal)
   	{
   		pal->add("potential", pot);
   		if(pal->query("potential") > pal->query("max_pot"))
   			pal->set("potential", pal->query("max_pot"));
   		pal->add_exp_combat(exp,this_object(),"��������");
   		//pal->add("combat_exp",exp);
   	}
   	
   	if(pal && user)
   		log_file("job/qqll",
   		sprintf("%s(%s)��%s(%s)�������������%d�㾭�飬%d��Ǳ��\n",
   		user->query("name"),user->query("id"),pal->query("name"), pal->query("id"), exp, pot));
   		
   	if(user) tell_object(user, HIW"������ɣ��㱻�����ˣ�\n" +
   	chinese_number(exp) + "��ʵս����\n" +
   	chinese_number(pot) + "��Ǳ��\n"NOR);
   
   	if(pal) tell_object(pal, HIW"������ɣ��㱻�����ˣ�\n" +
   	chinese_number(exp) + "��ʵս����\n" +
   	chinese_number(pot) + "��Ǳ��\n"NOR);
   }
   
   GIFT_D->check_count(user,this_object(),"��������",40);      
   user->set("job_name", "��������");
   user->add("job_time/��������",1);
   user->apply_condition("job_busy",1);
   if(pal)
   {
   	pal->set("job_name", "��������");
   pal->add("job_time/��������",1);
   	pal->apply_condition("job_busy",1);
   }
   
   if(user->query("job_time/��������") > 0 && user->query("job_time/��������") % 10 == 0 )
   {
   	message_vision(CYN"$Nת��Ҫ�ߣ�$n��Ȼ��ס��$N��˵������"+RANK_D->query_respect(user)+"������ô��ΰ��ң�ƶ��
�м���������ʵƶ���������Ҳ�����ʦ��ѵ���ƺ�Ҳ�����ã�"+RANK_D->query_respect(user)+"������
����ȥ�о�һ�£�����ƶ���������Ƿ�ȷʵ����\n"NOR,user,this_object());
   qqllyu = new(QQLLYU_OB);
   qqllyu->move(user);
   message_vision("$n��$Nһ"+qqllyu->query("unit")+qqllyu->name()+"��\n",user,this_object());
   	
   }   
      
   destruct(qqll);
   return 1;
}

private nomask void give_prize()
{
   object user, qqll, pal;
   int exp, pot;
   
   user = this_user();
   qqll = present("qiyan stone", user);
   exp = qqll->query("ok") * 150 + random(50);
   
   //exp  = exp * 3;
   exp = exp * 10 / 4;
   
   exp += random(exp);
            
   pot = exp / 5 + random(exp / 6);

   user->add("potential", pot);
   if(user->query("potential") > user->query("max_pot")) 
      user->set("potential", user->query("max_pot"));
   user->add("combat_exp",exp);
   	
   pal = qqll->query("pal", 1);
   if(pal)
   {
   	pal->add("potential", pot);
   	if(pal->query("potential") > pal->query("max_pot"))
   		pal->set("potential", pal->query("max_pot"));
	pal->add("combat_exp",exp);
	}
	
	
	if(pal && user)
		log_file("job/qqll",
      sprintf("%s %s(%s)��%s(%s)�������������%d�㾭�飬%d��Ǳ��\n",
         ctime(time())[4..15], 
         user->query("name"), user->query("id"),
         pal->query("name"), pal->query("id"), exp, pot));
                  
   if(user) tell_object(user, HIW"������ɣ��㱻�����ˣ�\n" +
      chinese_number(exp) + "��ʵս����\n" +
      chinese_number(pot) + "��Ǳ��\n"NOR);
   if(pal) tell_object(pal, HIW"������ɣ��㱻�����ˣ�\n" +
      chinese_number(exp) + "��ʵս����\n" +
      chinese_number(pot) + "��Ǳ��\n"NOR);
}
