// xiaofeng.c
// Add by tangfeng 2004

inherit F_MASTER;
#include <ansi.h>
inherit NPC;

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

int ask_truth();
int ask_yintui();
int ask_father();
void greeting(object me);
void xiaofeng_guiyin(object me);
void create()
{
	set_name("����", ({"xiao feng", "xiao", "feng"}));
	set("gender", "����");
	set("title",HIB"����"NOR);
	set("age", 58);
	set("long", 
		"������ؤ��ǰ�ΰ������塣\n"
		"������������࣬���ʮ�ֿ��࣬����һ�������ֿ���ʮ\n"
		"�����Ի������ӣ�˫Ŀ��磬��������\n");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 40000);
	set("max_qi", 40000);
	set("jing", 15000);
	set("max_jing", 15000);
	set("eff_jing", 15000);
	set("neili", 60000);
	set("max_neili", 35000);
	set("jiali", 200);
  set("max_jingli", 15000);
  set("jingli", 15000);
	set("eff_jingli", 15000);
  set("combat_exp", 10000000);	 
	set_skill("force", 420);   
	set_skill("bangjue", 200);
	set_skill("literate", 200);        
	set_skill("medicine", 200);        
	set_skill("huntian-qigong", 420);
	set_skill("yijin-jing", 200);     
	set_skill("strike", 420);           
	set_skill("jingang-quan", 420);     
	set_skill("xianglong-zhang", 420);     
	set_skill("dodge", 420);      	     
	set_skill("xiaoyaoyou", 420);   
	set_skill("parry", 420);          
	set_skill("stick", 420);          
	set_skill("dagou-bang", 420);          
	set_skill("cuff", 420);          
	map_skill("cuff", "jingang-quan");
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	map_skill("stick", "dagou-bang");
	prepare_skill("strike","xianglong-zhang");
	prepare_skill("cuff","jingang-quan");
  set("chat_chance_combat", 99);
  set("chat_msg_combat", ({
          (: exert_function, "huntian" :),
          (: exert_function, "shentong" :),
          (: perform_action, "strike.paiyun" :),
          (: perform_action, "strike.xiao" :),
  }));
  set("inquiry", ([
		"����" : random(2)?"�����Ҷ��ܡ�\n":"�Ҷ���һ���������˸�������񽣸���������˫��\n",
		"����" : random(2)?"���������ܡ�\n":"��������Ϊ��翹�������ֻ�����ڸ������Ĺ�������ү�ˡ�\n",
		"����" : (: ask_truth :),
		"��Զɽ" : (: ask_father :),
		"��ʦ" : "��....����ע��һ��Ư�����������˰ɡ�\n",
		"ؤ��" : "ؤ�����Ҽң��Ҽ���ؤ�",
		"ؤ��" : "��һ���书�������֣�Ҳ���ǰ�����ֵ��ӡ�",
		"������" : "�������Ǵ���μ���ѧ�����֮�ء�",
		"���߹�" : "������˵��һ����Ҳ����Ϊ����Ϊ���壬�书��ߡ�",
		"����" : "......������һ����Ψһ��ǣ���ˡ�",
		"����" : "��������Ҳ�գ����Ϲֵĵ��ӣ��Ǹ������ĺ�������",
		"����" : "��������ã���˵��Ľ�ݹ�����һ��",
		"������" : "�������Ǵ���μ���ѧ�����֮�ء�",
		"����ʮ����" : "���������߽����ĳԷ��Ķ�����������",
		"�򹷰�" : "ؤ�����֮�ⲻ��֮�书��ȷʵ�����ޱȡ�",
		"����" : (: ask_yintui :),
		"����" : (: ask_yintui :),
		"ϴ��" : (: ask_yintui :),
		"���˽���" : (: ask_yintui :),
		"��������" : (: ask_yintui :),
		"Ľ�ݸ�" : "Ľ�ݹ���ȷ���佭���Ĳɣ�ʫ���黭�����������书���ǹھ����¡�",
		"Ľ�ݲ�" : "����˵�ǣ�����Ľ�ݲ����Ľܲţ���ϧӢ�����š�",
		"������" : "��������߾�ѧ����������Ψ�Ҷ���������������ʹ�á�",
    ]));

	setup();
  carry_object(ARMOR_D("changshan"))->wear();
  carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
	object me,room;
	me = this_player();
	::init();
	if (interactive(me) && living(me)) {
  	if(!me->query_condition("killer")&&me->query(QUESTDIR3+"start") && me->query_temp(QUESTDIR3+"lookcliff")&& !me->query(QUESTDIR3+"over"))
    {
	    this_object()->set("qi", this_object()->query("max_qi"));
	    this_object()->set("eff_qi", this_object()->query("max_qi"));
	    this_object()->set("neili", this_object()->query("max_neili")*2);
      tell_object(me,CYN"�㾪�ȵء���������һ����\n"NOR);    
      message_vision(HIW"$N����������һ���������ƿ�������ȫ���ָ��ˡ�"NOR,this_object());                    
      tell_object(me,HIC"\n��û���ϵ������徹Ȼ�ָ����֮Ѹ�٣���Ȼ�ǹ����˵á�\n"NOR);  
      command("thank "+me->query("id"));
      //remove_call_out("greeting");
		  call_out("greeting",2,me);
    }
	 	if(!me->query_condition("killer")&& me->query(QUESTDIR4+"start") && me->query_temp(QUESTDIR4+"breakmen") && !me->query(QUESTDIR4+"over"))
    {
    	command("ah "+me->query("id"));
    	command("say û�뵽�����Ǵ���������ȡ�"); 
    	command("thank "+me->query("id"));
      me->start_busy(2);
		  tell_object(me,HIC"\n����ǰ˵���������ǻ��ǸϿ��뿪�˵أ�ֻ�����Ϊ��Ӫ���㣬����������ȫ������������ؤ����֡�����\n"
		                      "����Զ������������ʮ��������\n"NOR);
		  command("sigh");
		  command("say �ã�������͸Ͽ�һ�𴳳�ȥ��");
      if (!(room = find_object("/d/xingxiu/silk3")))
          room = load_object("/d/xingxiu/silk3");
      if(!room)
      { 
      	tell_object(me,HIR"\n�Ͽ���wiz�ɣ���Ȼ���䲻����!!!\n");
      }
      else
      {
                      me->set(QUESTDIR4+"over",1);
                      me->set(QUESTDIR+"time",time());
                      me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
                      me->delete_temp(QUESTDIR4+"dagouzhen");
                      me->delete_temp(QUESTDIR4+"shaolinzhen");
                      me->delete_temp(QUESTDIR4+"kill");
                      me->delete_temp(QUESTDIR4+"anhao");
                      me->delete_temp(QUESTDIR4+"count");
                      me->delete_temp(QUESTDIR4+"breakmen");
                      me->delete_temp(QUESTDIR4+"askxuanci");
                      me->delete_temp(QUESTDIR4+"askwu");
                  me->move("/d/xingxiu/daliao/shanlu3");
                  this_object()->move("/d/xingxiu/daliao/shanlu3");
                  me->move("/d/xingxiu/daliao/shanlu2");
                  this_object()->move("/d/xingxiu/daliao/shanlu2");
                  me->move("/d/xingxiu/daliao/shanlu1");
                  this_object()->move("/d/xingxiu/daliao/shanlu1");
                  "/cmds/std/look.c"->look_room(me,environment(me)); 
   		  me->move(room);
   		  this_object()->move(room);
   		  "/cmds/std/look.c"->look_room(me, room); 
        tell_object(me,HIG"\n���Ǳߴ���ˣ�һ·�����������߹��ü����ط���������һ�����±ߡ�Ҳ�ɣ��������ǵ�������˫��˫���ĵط���\n"NOR);
        message_vision(HIW"$N����������һ������\n"NOR,this_object());
   		  command("whisper "+me->query("id")+" Ҳ�����������ˣ�������ԭ����֮��Ķ���ԹԹҶһ�ʹ�����");
   		  command("chat* thank "+me->query("id"));
   		  command("wave "+me->query("id"));
   		  command("chat* byebye");
		    me->add("max_neili",me->query_skill("force")/2);
		    me->add("combat_exp",me->query_skill("force"));
		    me->add("shen",me->query_skill("force")*5);
		    me->add("mana",me->query_skill("force")/2);
        tell_object(me,HIY"\n����"+NATURE_D->game_time()+"���ڽ�����Ӵ��ɽ�ȳ��������"+(int)me->query_skill("force")/2+"�����������"+(int)me->query_skill("force")+"�㾭���"+(int)me->query_skill("force")/2+"��������\n\n");
        log_file("quest/TLBB", sprintf("%s(%s) ���ڽ�����Ӵ��ɽ�ȳ�����ʱ�� %s�����%d�����������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), ctime(time()),me->query_skill("force")/2,me->query_skill("force"),me->query_skill("force")/2) );
                    destruct(this_object());
                    return;
 	    }
    }
	} 
}

void greeting(object me)
{
	if(!me) return;
  if(environment(this_object())!=environment(me)) 
  {
    command("chat "+me->name()+"��ô������ݣ���Ȼ�޶��߿���");
    command("chat* heng "+me->query("id"));
    tell_object(me,HIG"\n�����������Ȼ�������ѣ�ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
    me->delete_temp(QUESTDIR3+"kill");
    me->delete_temp(QUESTDIR3+"lookcliff");
    me->delete(QUESTDIR3+"start");
    me->add("mana",-200);
    if(me->query("mana")<0) me->set("mana",0);
    return;
	}
	if(me->query(QUESTDIR3+"start") && me->query_temp(QUESTDIR3+"lookcliff")&& !me->query(QUESTDIR3+"over"))
  {
    command("thank "+me->query("id"));
    command("say �ٴθ�л��������֮����");
    tell_object(me,HIG"\n\n���߹�ȥ���˿����壬���ǽ��㿴���ĸ��������壺�ǹ��ʦ������ɽ�����������һ��Ƭ���Ǹ����ӡ�ۣ�\n"
                          "�Զ��׼��������˹��⽫���µ��ּ���ȥ�ˡ�\n"NOR);
	  tell_room(environment(me),HIG"\n"+me->name()+"�ߵ������ǰ������˵��Щʲô��\n"NOR, ({ me }));
    command("ah");
    message_vision(HIW"$NͻȻ��Ц�������૵��������������������ˣ�����Ĳ��Ǻ��ˡ���\n"NOR,this_object());
    command("say");
    message_vision(HIC"$N��ɫ������Щ���������ƺ��Ѿ���Щ����\n"NOR,this_object());
    tell_object(me,HIW"\nͻȻ֮�䣬����������������ͷ��һ����Ϊ��������ȷ�������ˣ������������Դ��Σ�ֻ�³�͢��֪���������\n"
                        "ɥ�������Ҵ�ʱ�������������֮�ʣ��������������Ĵ��ʱ��������һ������֮�ĸ����㣬���ȷ��С����Ϊ\n"
                        "һ�㲻��������������Ҳ�к��˻��ˣ�Ҳ�����������壬�α�ִ������ݡ�\n"NOR);
    tell_object(me,HIR"\nһʱ�䣬����Ȱ�������ask xiao about ������������Ϊ���ֳ�����kill xiao������һʱίʵ���Ծ�����\n"NOR);
    me->set(QUESTDIR3+"over",1);
    me->start_busy(3);
	}
}
int ask_father()
{
    object me;
    me=this_player();
    if(me->query(QUESTDIR4+"over"))
    {
    	command("say ��Զɽ�������Ҹ��ס����ѱ����ָ�ɮ��Ϊ���ӡ�");
		  return 1;
	  }
    if(me->query(QUESTDIR3+"over"))
    {
    	command("heng");
    	command("say ��Զɽ�������Ҹ��ס��˳��ܲ�����");
		  return 1;
	  }
    if(!me->query(QUESTDIR3+"over"))
    {
    	command("? "+me->query("id"));
		  return 1;
	  }
    command("? "+me->query("id"));
		return 1;
}
int ask_truth()
{
    object me;
    me=this_player();
    if(me->query(QUESTDIR4+"over"))
    {
    	command("say һ�ж��Ѿ���ȥ�������¿�ʼ�ɡ�");
		  return 1;
	  }
    if(me->query(QUESTDIR3+"over"))
    {
    	command("heng");
    	command("say �˵ȴ���ܲ�����");
		  return 1;
	  }
    if(!me->query(QUESTDIR3+"start"))
    {
    	command("? "+me->query("id"));
    	command("say ���У���ڻ�û��ʼ����Ҫclone�Һò���");
    	command("heng "+me->query("id"));
		  return 1;
	  }
	  if(me->query_condition("killer"))
	  {
	  	command("heng");
	  	command("say �㻹�Ǵ���ú͹ٸ��Ĺ�ϵ�ɡ�");
	  	return 1;
	  }
    if(me->query(QUESTDIR3+"start")&&!me->query_temp(QUESTDIR3+"help"))
    {
    	command("? "+me->query("id"));
    	command("say ��ô�������ҵ��ң�BUG��������˵��˭�ڰ��㣿");
		  return 1;
	  }
    if(me->query(QUESTDIR3+"start")&&me->query_temp(QUESTDIR3+"help")&&!me->query_temp(QUESTDIR3+"askxiao"))
    {
    	message_vision(HIY"$N����$n��ѯ�ʣ���ʱ�ƺ������˺ܶࡣ\n"NOR,this_object(),me);
    	command("say ��Ҳ��֪������ԭί����Щ���������������ð��������Ѷ������ѣ�������ʦ�����޶˱�����");
    	command("sigh");
    	command("say ������δ��Զ�У�������λ����ȥһ����Ħ�£������˵��һ����ּ��ص����¼���");
    	command("thank "+me->query("id"));
    	me->set_temp(QUESTDIR3+"askxiao",1);
		  return 1;
	  }
    command("thank "+me->query("id"));
    command("say һ�����ʹ����ˡ�");
		return 1;
}
int ask_yintui()
{
    object me;
    me=this_player();
    if(me->query(QUESTDIR4+"over"))
    {
    	command("say һ�ж��Ѿ���ȥ�������¿�ʼ�ɡ�");
		  return 1;
	  }
    if(me->query(QUESTDIR3+"good"))
    {
    	command("sigh");
    	command("say Ҳ�գ����ºδ������ˡ��⽭��������Ҳ�����ˣ��Ҽ��������ˣ�Ҳ�û��Ҵ��ɡ�");
    	command("bye");
   		destruct(this_object());
		  return 1;
	  }
	  if(me->query_condition("killer"))
	  {
	  	command("heng");
	  	command("say �㻹�Ǵ���ú͹ٸ��Ĺ�ϵ�ɡ�");
	  	return 1;
	  }
    if(!me->query(QUESTDIR3+"good") && me->query(QUESTDIR3+"over")&& !me->query(QUESTDIR3+"bad"))
    {
    	tell_object(me,HIW"�������������ɣ�֪������Ϊ�������˵��������ȴ������Խ��Խ���꣬�����ŽУ����Ҳ��Ǻ��ˣ��Ҳ��Ǻ��ˣ�\n"
    	                  "����������²������������²��������������һ������ɽ������ȥ������ʯм�Ľ����Ƿ�������ŭ���죬����һ���Ƶ�\n"
    	                  "��ȥ����Ҫ����һ�����������ܵ�����ί������Ҫ�����ʯ�ڷ�й�����ú��������Ƴ�Ѫ��һ����Ѫ��ӡ����ʯ�ڣ���\n"
    	                  "أ�Բ�ͣ��\n\n"NOR);
    	message_vision(HIY"$N���������������ɫȴ��Խ��Խ�Ǳ�ʹ��\n"NOR,this_object());
    	tell_object(me,HIW"��֪������������书������ʱȰ˵����ȱ���ֻ���ڹ��������ˣ�����������Цһ������Ȼ������ŭ�����㡣������\n"
    	                  "��˵���������ɷ�����𡢷ŵ��£��������к��˻��ˣ��������У���ȻҲ�к��˻��ˡ�����Ϊ�������ֵ���Σ�ֻҪ\n"
    	                  "�������壬�����»�����ҪȥҪ������\n\n"NOR);          	 
    	command("ah "+me->query("id"));
    	command("consider");
    	remove_call_out("xiaofeng_guiyin");
    	call_out("xiaofeng_guiyin",5,me);
		  return 1;
	  }
	  if(me->query(QUESTDIR3+"over")&& me->query(QUESTDIR3+"bad"))
	  {
   	  command("heng "+me->query("id"));
   	  kill_ob(me);
   	  return 1;
   	}
 	  command("heng "+me->query("id"));
		return 1;
}
void xiaofeng_guiyin(object me)
{
	if(!me) return;
  if(environment(this_object())!=environment(me)) 
  {
    command("chat "+me->name()+"��ô������ݣ���Ȼ�޶��߿���");
    command("chat* heng "+me->query("id"));
    tell_object(me,HIG"\n�����������Ȼ�������ѣ�ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
    me->delete_temp(QUESTDIR3+"kill");
    me->delete_temp(QUESTDIR3+"lookcliff");
    me->delete(QUESTDIR3+"start");
    me->delete(QUESTDIR3+"over");
    me->add("mana",-200);
    if(me->query("mana")<0) me->set("mana",0);
    return;
  }
  if(!me->query(QUESTDIR3+"good") && me->query(QUESTDIR3+"over")&& !me->query(QUESTDIR3+"bad"))
  {
    command("nod "+me->query("id"));
    tell_object(me,HIG"\nȴ��������ɫ������ͣ�������ԭ���Ĵ��ǻۣ�Ҳ�������������еĵ�����Ҳ����������\n"NOR);
    command("say Ҳ�գ�����ͻ��Ҵ��ɣ������Լ��������������壬��������Ը�������");
    command("thank "+me->query("id"));
    command("bye");                     
    me->set(QUESTDIR3+"good",1);
		me->add("mana",me->query_skill("force")/2);
		me->add("shen",me->query_skill("force")*5);
    tell_object(me,HIY"\n\n����"+NATURE_D->game_time()+"ѡ��Ȱ˵�������������Ҳ�㹦�����������"+(int)me->query_skill("force")/2+"�������Ľ�����\n\n");
    log_file("quest/TLBB", sprintf("%s(%s) ѡ��Ȱ˵�������������ʱ�� %s�����%d��������\n", me->name(1),me->query("id"), ctime(time()),me->query_skill("force")/2) );
	  destruct(this_object());
	}
}
void die()
{
	object me,ob=this_object();
	me=ob->query_temp("last_damage_from");
        if(userp(me=ob->query_temp("last_damage_from")) 
	  && me->query(QUESTDIR3+"over")
	  && !me->query(QUESTDIR3+"good")
	  && !me->query(QUESTDIR3+"bad"))
	{
 	  me->set(QUESTDIR3+"bad",1);
 	  command("chat* heng");
    command("chat �úã�"+me->name()+"��Ȼ���Ҳ�ע��͵Ϯ�ң������书�ָ�֮�գ�������ԭ����Ѫϴ֮ʱ��");
		me->add("max_neili",me->query_skill("force")/2);
		me->add("shen",-me->query_skill("force")*5);
    tell_object(me,HIY"\n\n����"+NATURE_D->game_time()+"ѡ��Ϊ���ֳ������������壬���"+(int)me->query_skill("force")/2+"�������Ľ�����\n\n");
    log_file("quest/TLBB", sprintf("%s(%s) ѡ��������壬ʱ�� %s�����%d��������\n", me->name(1),me->query("id"), ctime(time()),me->query_skill("force")/2) );
	  destruct(this_object());
  }
  else if(this_object()->query("no_death"))
  {
	ob->set("qi", 20000);
	ob->set("eff_qi", 20000);
	ob->set("jing", 15000);
	ob->set("max_jing", 15000);
	ob->add("neili", 8000);
  ob->set("jingli", 15000);
	ob->set("jing", 15000);
  command("heng");
  message_vision(HIR "\n$N΢һ�����������������ȫ��ǽڷ���һ�󱬶�������졣\n" NOR, ob);
	}
   ::die();
}
void unconcious()
{
  die();
}
