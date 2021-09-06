// yideng.c һ�ƴ�ʦ By River@SJ 2002.6.6

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_hr();
int ask_qiu();
int ask_xtg();

void create()
{
	set_name("һ�ƴ�ʦ", ({ "yideng dashi", "yideng", "dashi" }) );
	set("title",HIW"�ϵ�"NOR);
	set("gender", "����" );
	set("class", "bonze");
	set("age", 78);
	set("str", 35);
	set("con", 40);
	set("dex", 35);
	set("int", 35);
	set("per", 28);
	set("unique", 1);

	set("max_qi", 12000);
	set("max_jing", 7500);
	set("eff_jingli", 8500);
	set("neili", 22000);
	set("max_neili", 22000);
	set("jiali", 150);
	set("combat_exp", 4900000);
	set("score", 20000);

	create_family("������", 12, "�׼ҵ���");

	set("long", "һ�����ֲ�ɮ�ۣ����������İ�ü���۽Ǵ�����������Ŀ���飬\n"+
		"ü����������࣬��һ��Ӻ�ݸ߻�����ɫ��ȴ��һ����֪��\n");

	set("combat_exp", 4900000);

	set_skill("parry", 400);
	set_skill("dodge", 380);
	set_skill("qingyan-zhang", 380);
	set_skill("strike", 380);
	set_skill("buddhism",200);
	set_skill("force", 400);
	set_skill("literate", 250);
	set_skill("sword", 180);
	set_skill("duanjia-jianfa", 380);
	set_skill("cuff", 200);
	set_skill("axe",200);
	set_skill("pangen-fu",380);
	set_skill("duanjia-quan", 400);
	set_skill("yiyang-zhi", 400);
	set_skill("finger", 400);
	set_skill("qiantian-yiyang", 400);
	set_skill("tianlong-xiang", 400);

	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "duanjia-jianfa");
	map_skill("sword", "duanjia-jianfa");
	map_skill("force", "qiantian-yiyang");
	map_skill("cuff", "duanjia-quan");
	map_skill("strike", "qingyan-zhang");
	map_skill("finger","yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");
	
	
	set("inquiry", ([
		"here": "�������ʯ�ݡ�",
		"����": (: ask_hr :),
       "�ȶ�": (: ask_qiu :),
      	"һ��ָ": (: ask_xtg :),
//    	"ѧϰ": (: ask_quest :),
	]));

	setup();
	carry_object("/d/tls/obj/jiasha")->wear();
	carry_object("/d/tls/obj/sengxie")->wear();
}

void attempt_apprentice(object ob)
{
	if ( ob->query_skill("qiantian-yiyang",1) < 180 ){
		command ("hmm");
		command ("say ��Ǭ��һ�������֮��ҿɲ����㣡");
		return;
	}
	if( ob->query_int(1) < 34){
		command("say ��ѧ֮���������Ըߣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ�������");
		return;
	}
	if(ob->query("shen") < 0){
		command("say ���������û��ң�����λ" + RANK_D->query_respect(ob) + "��¶�׹⣬�ҿ����ʺ����Ҵ������ȥ�ˡ�");
		return;
	}
	if(ob->query_skill("liumai-shenjian", 1)){
		command("say ��λ" + RANK_D->query_respect(ob) +"�Ѿ�ѧ���������񽣣������ʺϰ���Ϊʦ�ˡ�");
		return;
	}
/*
	if (ob->query("tls")) {
		command ("say ���Ѿ��������³��ҵ����ˣ��Ҳ����������ˣ�");
		return;
	}
*/
	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
	command("recruit " + ob->query("id") );
	ob->delete("tls");
	ob->delete("class");
	ob->set("title",HIW"������ϵ۴���"NOR);
}

int ask_hr()
{
	object me= this_player();
	if (me->query_temp("quest/jindaoheijian/huangrong3")!=1) {
		command("say С���ﻹ�ðɣ�");
		command("haha");
		return 1;
	}

	command("say ��20�����ˣ���ǧ�߻������ء�");
	command("say ��֪�����ܰ�æ��");
	message_vision(WHT"�㽫�ڻ��������ʦ�����������һ�ƴ�ʦ!\n"NOR,me); 
	command("say �ðɣ�����ȥ����ȣ������ʹ��ȶ���ȥ��");
	command("say ����ԩԩ�౨��ʱ���ˣ�");
	me->delete_temp("quest/jindaoheijian/huangrong3");
	me->set_temp("quest/jindaoheijian/yideng",1);
	return 1;
}

int ask_qiu()
{   
    object me= this_player();
    if (me->query("quest/tzauto/pass")|| me->query("family/family_name")!="���ư�")
                 {   
                    command(" say �ȶ���Ը���ˣ���Ը��մȾ����֮�£�ʩ����ذɡ�");
                    return 1;
                  }
    command("say ��������Ƶ����˵���ɹŴ���ù��������£������Ƶ��Ϲ������Ա�ؾ��ػأ�����������\n");
    command("say �ȶ�����������ʹ�����ȥ��̽��Ϣ���Ѿ�������ҹû�����ˡ�\n");
     me->set_temp("quest/tzauto/yideng",1); 
  return 1;

}

 int accept_object(object me, object ob)
 
  {
 if( ob->query("id") == "lingwen" 
      && me->query("family/family_name")=="ȫ���"
      && me->query_temp("quanzhen/force") 
      && !me->query("quanzhen/force")    )
   	   {
               command("ah ");
               command("say �벻������֮�껹��Ŀ���������˵��ּ��� "); 
               me->delete_temp("quanzhen/force");
  message_vision(HIM"һ�ƴ�ʦ�������еġ���ƪ����������Ĭ�˰��죬���ɵ�����̾��һ����������һ�γ���������������\n"NOR+
                          HIG"ԭ�����껪ɽ�۽�֮���������˶��ϵ۶���ү��һ��ָ��Ϊ������ڶ���ͺ���ʦ�����´������ϵۻ����д蹦��\n"+
                               "�ϵ۽�һ��ָ��Ҫּ���ϣ�����˵������������֪������������ʮ��ϲ���������������������칦���򴫸��˶���ү��\n"+
                               "���������ٱ�֮���Ե����������Ҿɼ��ַ������ǲ����������������칦���д��ˣ��ټ��ϻ�ү��һ��ָ�񹦣�������\n"+
                               "�п��Ƹ�󡹦֮�ˣ��Ͳ��������������ˡ��� \n"NOR, me);
               command("say ��ʱ���ķ������ף���������ǧ����������������ּ��Ҫ�����칦�������ģ�Ҫ��������֮������һ����������ŷ����֮�ˡ� ");         
               command("sigh ");     
           
               me->set_temp("xtg1",1);
               me->set("give_book",1);
         call_out("destructing", 1, ob); 
                return 1; 
      }
   else return 0;
             }

int ask_xtg()
{
	object me= this_player();
	if (!me->query_temp("xtg1")&& !me->query("give_book")) {
		command("say һ��ָ���Ҵ���μҵļҴ�������");
		return 1;
	}

if( me->query("quanzhen/force")== "pass")
{   command("say ������С���Ѿ���ȫ������һ��ָ��Ҫּ�����ˡ�");
  me->set("title",HIR"ȫ����ƽ�"HIR" "HIC"���칦����"NOR);
      command("haha ");
return 1;
}
if( (me->query("combat_exp") - me->query("xtg/dyz/exp") <100000 && !me->query("cw_exp")) ||  me->query("quanzhen/force")== "try"   )
	{
				command("say ������С�ѻ��ö����ϰ���С�");
						return 1;
		}

   if( time()-me->query("xtg/dyz/time")<86400)		
   		{
				command("say С�ѻ���ȥ��Ϣһ�°ɡ�");
						return 1;
		}

	command("say ��������ѧ��һ��ָ���������ã���δ��ϰ����˵Ҳû����ͽ�ܡ�");
    command("say ���������Ѹߣ�����Ҳ��˶���ˡ���˵����ŷ�������д��ˣ�����֮�ϣ�Ψ���칦��һ��ָ�����񼼲��ܿ��Ƹ�󡹦��");
    command("say ��Ȼ��õ����������˵����칦��Ҫ�����ı㽫��һ��ָ���ڸ��㣬�㵱������ϰ����Ҫ���������˺���������");


     message_vision(HIY"һ�ƴ�ʦ���Ƹ��أ�����ʳָ����������仺��$N�ϰ��������Ѩȴ��ȫ��һָ����֮�£�����֪Ҫ�������һ��Ѩ�����Ŵ���Ѩ�Դ�ָ֮�ݣ�\n"NOR+
                        HIG"һ�ƴ�ʦ����δ�꣬��������������һָ��������ȴ��ָ��$NС������һָ�����ֵ�ҪѨ���㣬�Ǹ������ʮ����Ѩ��������\n"+
                               "ͨ�ȣ�������ע��������ֱ�ֺ�ǡ���������������һָ����֮�¡�\n"+
                        HIM"����һ�ƴ�ʦ����ָ�ֳ�����һָѸ�����磬ֱָ$Nü�ģ�ָ���������ƺ�ͷ��̫�������У��ٻᣮ���ȸ���ҪѨ������һָ���֡� \n"NOR, me);
    command("smile ");
    command("say ��ɿ������ˣ�");
me->delete_temp("xtg1");
 tell_object(me,HIY"\n�㿪ʼ����Ļ���һ�ƴ�ʦ��һ��һʽ����\n"NOR);
       me->start_busy(999);              
       remove_call_out("thinking");
           call_out("thinking",5, me );

	return 1;
}



int thinking(object me)
{
  int i,j,total;
  if(!me) return 0;
	
  if(me->query_temp("try_yyz")<(3+random(3)))
    { me->add_temp("try_yyz",1);
          if(random(2)) tell_object(me,HIG"\n����������Ÿղ�һ�ƴ�ʦ��һ��һʽ...\n"NOR);
             else tell_object(me,HIY"\nͻȻ�䣬���ƺ�ץ����ʲô...\n"NOR);
	  tell_room(environment(me),HIC""+me->query("name")+"�ƺ���˼����ʲô��üͷ���塣\n"NOR, ({}));
	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);
	}

else
   {  me->delete_temp("try_yyz");


j = 25;
if(me->query("m-card-vip")) j =  22;
if(me->query("y-card-vip")) j =  20;
if(me->query("buyvip"))     j =  15;
i=random(j);

if (i == 10 && random(me->query("kar"))>=28 )
{
        tell_object(me,HIM"\n�����칦���������У���ȱ�裬��������أ���������������֮����һ��һ����������������������ת���ݣ�\n"NOR);
    message_vision(HIC"\n$N�����ʹ��һ��ָָ���������칦�����ƺ���Щ�˽��ˡ���\n"NOR,me); 
     tell_object(me,HIR"������ʹ��һ��ָָ���������칦�����ƺ���Щ�˽��ˣ�ʣ�µľ����ڼ���ϰ�ˣ�\n"NOR);
     me->set("quanzhen/force", "try" );
  me->set("title",HIC"ȫ������칦����"NOR);
       log_file("quest/quanzhen/force", sprintf("%s(%s) ʧ��%d�γɹ��⿪�����롣��Դ��%d�����飺%d��\n",   
          me->name(1),
          me->query("id"), 
          me->query("xtg/dyz/fail"),
          me->query("kar"),
          me->query("combat_exp")) );
me->start_busy(1);
     }

    else
    {
       tell_object(me,HIG"\n���˼��ã�����Ҫ�졣\n"NOR);
       message_vision(HIC"\n$Nҡ��ҡͷ�������̾�˿�����\n"NOR,me); 
      tell_object(me,HBBLU"\n�ܿ�ϧ���㱾�γ������칦����������ʧ�ܣ�\n"NOR);
   tell_object(me,HBBLU"��Ŀǰ�ľ�����" + me->query("combat_exp") + "������ʱ�����齣"+ NATURE_D->game_time() + "�����¼��\n"NOR);
      tell_object(me,HBBLU"�㽫�ڼ��24Сʱ������100Kʵս���������һ�λ��ᣡ��\n\n"NOR);
       me->add("xtg/dyz/fail",1);
       me->set("xtg/dyz/exp", me->query("combat_exp") );
       me->start_busy(1);
  me->set("xtg/dyz/time",time());
    }

  }

}

