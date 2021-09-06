// NPC :yu_guangbiao.c �����
// By River 98/12
inherit NPC;
#include <ansi.h>

#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"

void create()
{
        set_name("�����", ({ "yu guangbiao", "yu", "guangbiao"}));
        set("title","���������ڵ���");              
        set("gender", "����" );
        set("age", 36);
        set("str", 27);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 15);
   	set("attitude", "friendly");

        set("max_qi", 1000);
        set("max_jing", 800);
        set("eff_jingli", 800);
        set("neili", 1000);
	set("qi", 1000);	
        set("max_neili", 1000);      
        set("unique", 1);
        
        set("long","�������������ڵĵ��ӡ�\n");
        set("combat_exp", 200000);
        set("shen", 800); 

        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("cuff", 80);
        set_skill("sword", 80);
        set_skill("qiantian-yiyang", 80);   
        set_skill("xiaoyaoyou", 80);
        set_skill("wuliang-jianfa", 80);
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuliang-jianfa");
        map_skill("sword", "wuliang-jianfa");
        map_skill("force", "qiantian-yiyang");         

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/dali/wuliang/npc/obj/changpao")->wear();
}
void die()
{
	object me,ob=this_object();
  me=ob->query_temp("last_damage_from");
 if(!me) return;

        if(objectp(me)
      && !present("wu guangsheng", environment(me))
      && me->query(QUESTDIR1+"start")
      && !me->query(QUESTDIR1+"wuliangover")
      && !me->query_temp(QUESTDIR1+"jianying")
     || me->query_temp("marks/ljg/gotolqs")  )
	{
    tell_object(me,HIY"\n��"+ob->name()+"�ۼ���Ҫɥ����ͻȻ�����������ģ���������ں�ɽ��Ӱ�����ܡ�\n"NOR);
	  tell_room(environment(me),HIC"\nֻ����������ƺ�����������"+me->query("name")+"�ƺ��ֽ���ʲô��\n"NOR, ({ me }));
	  me->set_temp(QUESTDIR1+"jianying",1);
    tell_object(me,HIY"\n��"+ob->name()+"��˵�����ɽһ�����±ߣ�һ�鳣�������ϳ������轣����Ӱ����ʱ�����ӣ���ʱ��Ů�ӣ�\n"
                       "��ʱ������Ů��ʹ��������̡�����������ֵĽ���֮������˵����������ഫ������ʹ����\n"NOR);

    tell_object(me,HIC"\n������"+ob->name()+"֮�󣬺ٺ��������������²������档\n"NOR);
	  tell_room(environment(me),HIC"\n�����˵��ܶ�֮��Ȼ����֪Ϊ�Σ��ƺ���Ѫһ�𣬺���ʧȥ��ʲô�Ƶģ�����ή�ҵ��ء�\n"NOR, ({ me }));
    message_vision(HIG"$n���쳤̾��Ϊʲô����Ϊʲô��$N��Ȼ��˺��ġ�\n"NOR, me, this_object());
  }
  
  if( me->query_temp("marks/ljg/gotolqs") ) {
  	 me->delete_temp("marks/ljg/gotolqs");
	  me->delete_temp(QUESTDIR1+"jianying",1);
  	    me->set("marks/xiaoyao", "gotofind");	
  	}
	::die();
}
