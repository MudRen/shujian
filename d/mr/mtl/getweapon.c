// mr up_uweapon_feature.c
// be jpei 2010

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIW"������-�����"NOR);
	
        set ("long",@long
������٢��ɽׯ����书�ؼ��ĵط���һ�������������İڷ��Ÿ�����
�����ƺ�������δ����������(cuilian weapon)�йء�
long);
	set("exits",([
		"out" : __DIR__"huandong",
	]));


	set("no_fight", 1);
	setup();
}


void init()
 {
         add_action("do_canwu", "cuilian");
 }



int do_canwu(string arg)
 {
     object me = this_player();
     object wpn;

     if(arg != "weapon")
           return notify_fail("����ֻ�ܴ���(cuilian)���(weapon)!\n");

 if(  !objectp(wpn = me->query_temp("weapon") ))
        return notify_fail("��û������Я�������������������޷����ġ�\n");    

     wpn = me->query_temp("weapon");

if(wpn->query("maker")=="Τ������(Weilan tiejiang)") 
          return notify_fail(HIR"\n�����Ž�������ע��"+wpn->query("weapon_mp/name")+""HIR"�С�������\n"HIG"���ɥ�ķ��֣�"+wpn->query("weapon_mp/name")+""HIG"δ����������̶Ѫ�����޷���������������ơ�\n\n"NOR);

     if (me->is_busy() || me->is_fighting()|| me->query_temp("con_weapon") )
       return notify_fail("����æ���ء�\n");

 if (me->query_temp("canwu_now") )
       return notify_fail("����æ���ء�\n");
       
       if (query_temp("canwu") )
       return notify_fail("�������ڲ����أ����һ��ѡ�\n");

     if( me->query("combat_exp",1)<10000000)
         
        return notify_fail("����ҵķ��˷�����ϵĲ��飬������������ݸ���Ī�⣬�޷���⣬���ɵ�ҡ��ҡͷ��\n");

       

     if(wpn->query("id")=="songwen jian")
   
              return notify_fail("�㷢�������ƹŽ�������Ȼ��������ʣ������ò��Ŵ�����\n");

     if( wpn->query("weapon_mp/owner",1)!= me->query("id") )   
          return notify_fail("�Ⲣ�������Լ���˽����������ο໨������ȥ���������ء�\n");

// if ( wpn->query("weapon_mp/weapon_prop/damage",1)      >=300
if(  wpn->query("weapon_mp/weapon_prop/attack",1)      >=150
|| wpn->query("weapon_mp/weapon_prop/dexerity",1)     >=20
|| wpn->query("weapon_mp/weapon_prop/constitution",1) >=20
|| wpn->query("weapon_mp/weapon_prop/intelligence",1) >=20
|| wpn->query("weapon_mp/weapon_prop/strength",1)     >=20 )

                 return notify_fail("���������ǵ�����һ������������������ԣ���������Ҫ�ټӴ����ˡ���\n");

       message_vision( HIW"$N��ϸ�ķ���������ϵĲ��飬��������δ�����������ݺܸ���Ȥ��\n"NOR,me);
       message_vision( HIW"$Nһͷ���������.��ͣ�ķ����š��� \n"NOR, me);
  
       me->start_busy(100);  
       me->set_temp("canwu_now",1); 
       set_temp("canwu",1);            
     call_out("thinking",5, me );
         return 1;

 }

int thinking(object me)
{
 int d,a,dexe,cons,inte,stre,t,cj,max_cj,yd,fld,exp,temp;
  object wpn;
  wpn = me->query_temp("weapon");
  if(!me) return 0;
	
  if(me->query_temp("con_weapon")<(3+random(3)))
       {  me->add_temp("con_weapon",1);
          if(random(2)) tell_object(me,HIG"\n����ϸ���ж�������������ݣ�ֻ���ö�Ŀһ��...\n"NOR);
                   else tell_object(me,HIY"\n����������������ص����ݣ������Ľ��������뵽����֮��...\n"NOR);  

	  tell_room(environment(me),HIC""+me->query("name")+"Ĭ������������"+wpn->query("weapon_mp/name")+""HIC"�����ķ���һ������Ĺ��...\n"NOR, ({}));

	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);

	}

 else { 
         me->delete_temp("con_weapon");
         me->start_busy(1);     
  message_vision(HIC"\n$N����"+wpn->query("weapon_mp/name")+""HIR"�����������ƺ������˲������ԣ���\n"NOR,me); 
  
     tell_object(me,HIR"\n���"+wpn->query("weapon_mp/name")+""HIR"�ɹ��Ľ�����һ�δ�����\n"NOR);
       me->add("combat_exp",-500000);
temp=5+random(5);
   wpn->add("weapon_mp/weapon_prop/damage",temp) ;
       if(wpn->query("weapon_mp/weapon_prop/damage",1) >300)  
          wpn->set("weapon_mp/weapon_prop/damage",300) ;
temp=3+random(2);
   wpn->add("weapon_mp/weapon_prop/attack",temp);
       if(wpn->query("weapon_mp/weapon_prop/attack",1) >150)
          wpn->set("weapon_mp/weapon_prop/attack",150);
temp=random(5);
 if(temp>=3)   wpn->add("weapon_mp/weapon_prop/dexerity",1);
       if( wpn->query("weapon_mp/weapon_prop/dexerity",1)>20)
          wpn->set("weapon_mp/weapon_prop/dexerity",20);


temp=random(5);
 if(temp>=3)    wpn->add("weapon_mp/weapon_prop/constitution",1);
       if( wpn->query("weapon_mp/weapon_prop/constitution",1)>20)
          wpn->set("weapon_mp/weapon_prop/constitution",20);
temp=random(5);
 if(temp>=3) 
   wpn->add("weapon_mp/weapon_prop/intelligence",1);
       if( wpn->query("weapon_mp/weapon_prop/intelligence",1)>20)
          wpn->set("weapon_mp/weapon_prop/intelligence",20);
temp=random(5);
 if(temp>=3) 
   wpn->add("weapon_mp/weapon_prop/strength",1) ;   
      if( wpn->query("weapon_mp/weapon_prop/strength",1)>20)
          wpn->set("weapon_mp/weapon_prop/strength",20);
   wpn->add("weapon_mp/dur",10000) ;   
   wpn->add("weapon_mp/max_dur",10000) ;   
   wpn->add("dur",10000) ;   
   wpn->add("max_dur",10000) ;   
   wpn->add("sharpness",1) ;   
   wpn->add("weapon_mp/sharpness",1) ;   
   wpn->add("weapon_mp/rigidity",1) ;   
   wpn->add("rigidity",1) ;   


d= wpn->query("weapon_mp/weapon_prop/damage",1);
a= wpn->query("weapon_mp/weapon_prop/attack",1);
dexe= wpn->query("weapon_mp/weapon_prop/dexerity",1);
cons= wpn->query("weapon_mp/weapon_prop/constitution",1);
inte= wpn->query("weapon_mp/weapon_prop/intelligence",1);
stre= wpn->query("weapon_mp/weapon_prop/strength",1) ;   
cj=wpn->query("weapon_mp/dur",1);
max_cj=wpn->query("weapon_mp/max_dur",1);
yd=wpn->query("weapon_mp/rigidity",1);
fld=wpn->query("weapon_mp/sharpness",1);
    me->add("relife/weapon",1); 
    t= me->query("relife/weapon",1);
    me->delete_temp("canwu_now");   
    delete_temp("canwu");   

    tell_object(me,HBBLU"\n�㱾�δ������ķ��������ʵս���飬���"+wpn->query("weapon_mp/name")+""HBYEL"��������Ϊ��\n"NOR);
    tell_object(me,HIM"\n�־�����һ��㣬ĿǰΪ��"+HIW+chinese_number(cj)+NOR+"����"+HIC+chinese_number(max_cj)+NOR+"����\n"NOR);
    tell_object(me,HBRED"Ӳ�ȣ�"+HIR+chinese_number(yd)+HIG+"��������"+HIW+chinese_number(fld)+NOR+"��\n"NOR);
    tell_object(me,HBMAG"������"+HIR+chinese_number(d)+HIR+"������"+HIW+chinese_number(a)+HIW+"��\n"NOR);
   tell_object(me,"��������"+HIG+chinese_number(stre)+NOR+"�㣬��"+HIM+chinese_number(dexe)+NOR+"�㣬����"+HIC+chinese_number(cons)+NOR+"�㣬����"+HIY+chinese_number(inte)+NOR+"�㡣\n"NOR);


      log_file("canwu/getexp", sprintf("%s(%s) ��%d�β�������������֣���������%d������%d����%d��%d��%d��%d�� ��ǰ���飺%d��\n", 
       me->name(1),
       me->query("id"),
       t,
       d,
       a,
       stre,  
       dexe,
       cons,
       inte,
       me->query("combat_exp")) );
  
   }

}
