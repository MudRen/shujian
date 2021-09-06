// 测试装备 by hongba
#include <armor.h>
#include <ansi.h>
inherit CLOTH;


// 函数：所属类别
int query_xy() { return 1 ; }


void create()
{
	set_name(CYN"天琊·狼牙战袍"NOR, ({"langya zhanpao"}) );
	set_weight(400);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("value", 0);
		set("armor_prop/armor", 0);
             set("armor_prop/parry", 0);
              set("armor_prop/dodge", 0);
              set("armor_prop/dexerity",0);
              set("armor_prop/strength",0);
              set("armor_prop/intelligence",0);
              set("armor_prop/constitution",0);
            
            set("armor_prop/neili",0);
            set("armor_prop/qi",0);
            set("armor_prop/attack",0);
            set("zhiliang",0);
            set("wear_con",35);
           set("dur",3000);
           set("gender","男性");
set("male_only",1); 
set("wear_maxneili",3000);
set("canjinglian",1);


	}
	setup();
}
int ob_hit(object ob, object me,int damage)
{
        
         int p;
        string msg;
if (!me->query_temp("armor/cloth") || !me->query_temp("armor/waist")
|| !me->query_temp("armor/wrists")|| !me->query_temp("armor/surcoat")
|| !me->query_temp("armor/shield")|| !me->query_temp("armor/hands")
|| !me->query_temp("armor/boots")|| !me->query_temp("armor/head"))
return 1;

                      if (me->query_temp("armor/cloth")->query("id") == "langya zhanpao"
        && me->query_temp("armor/waist")->query("id") == "langya huyao"
 &&  me->query_temp("armor/wrists")->query("id") == "langya huwan"
 &&  me->query_temp("armor/surcoat")->query("id") == "langya pifeng"
 &&  me->query_temp("armor/shield")->query("id") == "langya dunpai"
 &&  me->query_temp("armor/hands")->query("id") == "langya shoutao"
 &&  me->query_temp("armor/boots")->query("id") == "langya zhanxue"
 &&  me->query_temp("armor/head")->query("id") == "langya toukui")


       {
                msg = CYN"$n装备的惊人之处此时方显露出来，只见$n连连发起抢攻。$N慌乱之中，招式竟然一片混乱。\n"NOR;
               ob->start_busy(random(4));
                ob->receive_damage("qi", damage);
                ob->receive_wound("qi", damage);
                 COMBAT_D->do_attack(ob, ob, ob->query_temp("weapon"), damage);
                 p = (int)ob->query("eff_qi")*100/(int)ob->query("max_qi");
                msg += "( $N"+COMBAT_D->eff_status_msg(p)+" )\n";
                message_vision(msg, ob,me);
             return -damage/5;
        }

       
}


int query_autoload()
{

object me = environment();  

int j;   
object ob = this_object();
	string name,gender,str,temp_str,equip_zl,chars;
	int weight,level,value,armor,ap,dp,pp,hp,mp,wear_con,lasting,cp,zl,zj,strs,dex,ints,cons,jing,jingli,max_neili;
             

if (!me || !interactive(me) || !living(me))   
                return 0;



 
   
if( me->query("jinglian/langya zhanpao"))
{
j = me->query("jinglian/langya zhanpao");

             set("armor_prop/armor", j*30);
             set("armor_prop/parry", j*30);
             // set("armor_prop/dodge", j*30);
            //  set("armor_prop/dexerity",j);
            //  set("armor_prop/strength",j);
             // set("armor_prop/intelligence",j);
             // set("armor_prop/constitution",j);

           // set("armor_prop/neili",200+j*10);
          //  set("armor_prop/qi",200+j*10);
            set("armor_prop/attack",j*30);
set("dur",3000+j*500);
            set("zhiliang",j);
if(!ob->query("long"))
	{
		name = ob->query("name");
		gender = ob->query("gender");
		weight = ob->query_weight();
		level = ob->query("level");
		value = ob->query("value");
		armor = ob->query("armor_prop/armor");

		pp = ob->query("armor_prop/armor");
		hp = ob->query("armor_prop/qi");
		mp = ob->query("armor_prop/neili");
		wear_con = ob->query("wear_con");
                cp = ob->query("armor_prop/attack");
		ap = ob->query("ap");
		dp = ob->query("dp");
		zl = ob->query("zhiliang");
		lasting = ob->query("dur");
		zj = ob->query("_level");
		strs = ob->query("armor_prop/strength");
		dex = ob->query("armor_prop/dexerity");
		ints = ob->query("armor_prop/intelligence");
		cons = ob->query("armor_prop/constitution");
		jing = ob->query("jing");
		jingli = ob->query("jingli");
              max_neili = ob->query("wear_maxneili");
		switch(zl)
		{
			case 1  : equip_zl = HIG"魂魄☆"NOR; break;
			case 2  : equip_zl = CYN"恶鬼☆☆"NOR; break;
			case 3  : equip_zl = HIB"鬼仙☆☆☆"NOR; break;
                     case 4  : equip_zl = HIC"地仙☆☆☆☆"NOR; break;
                     case 5  : equip_zl = HIY"人魔☆☆☆☆☆"NOR; break;
case 6  : equip_zl = HIW"人仙☆☆☆☆☆☆"NOR; break;
case 7  : equip_zl = WHT"仙魔☆☆☆☆☆☆☆"NOR; break;
case 8  : equip_zl = HIM"仙灵☆☆☆☆☆☆☆☆"NOR; break;
case 9  : equip_zl = YEL"圣灵☆☆☆☆☆☆☆☆☆"NOR; break;

			default : equip_zl = WHT"凡人"NOR; break;
		}
		
		chars =HIY+"("+equip_zl+")"+NOR;
		
                                  if(zj) temp_str = zj+name+chars;
                                  else temp_str = name+chars;
		   str=YEL"┏━━━【"NOR+temp_str+YEL"】━━━┓\n"NOR;;
         str += sprintf(NOR YEL"┣━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓\n"NOR);
                            		  
                                str+=sprintf("%s  %-"+(28)+"s%s\n",YEL+"┃"+NOR,
                                                    "    装备防御："+CHINESE_D->chinese_number(armor)+"( "+ CHINESE_D->chinese_numbe(dp) +" )",YEL+"┃"+NOR);         
                                str +=HIM"┣附加━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫\n"NOR;   
		if(hp)
		{
			  str+=  sprintf("%s  %-"+(28)+"s%s",HIM+"┃"+NOR,"    气血加成："+CHINESE_D->chinese_number(hp),HIM+"┃"+NOR);      
		}
		if(mp)
		{
			 str+=sprintf("%-"+(30)+"s%s\n","    内力加成："+CHINESE_D->chinese_number(mp),HIM+"┃"+NOR); 	
		}

		if(pp)
		{
			  str+=sprintf("\n%s  %-"+(28)+"s%s",HIM+"┃"+NOR, "    追加防御："+CHINESE_D->chinese_number(pp),HIM+"┃"+NOR);      
		}

		if(cp)
		{
			 str+=sprintf("%-"+(30)+"s%s\n","    增强攻击："+CHINESE_D->chinese_number(cp),HIM+"┃"+NOR); 
		}

		if(ap)
		{
			 str+=sprintf("\n%s  %-"+(28)+"s%s",HIM+"┃"+NOR, "    追加攻击："+CHINESE_D->chinese_number(ap),HIM+"┃"+NOR);      
		}
		if(strs)
		{
			 str+=sprintf("%-"+(30)+"s%s\n","        臂力增加："+CHINESE_D->chinese_number(strs),HIM+"  ┃"+NOR); 
		}
		if(dex)
		{
			 str+=sprintf("\n%s  %-"+(28)+"s%s",HIM+"┃"+NOR, "    身法增加："+CHINESE_D->chinese_number(dex),HIM+"┃"+NOR);      
		}
		if(ints)
		{
			 str+=sprintf("%-"+(30)+"s%s\n","    悟性增加："+CHINESE_D->chinese_number(ints),HIM+"┃"+NOR); 
		}
		if(cons)
		{
			str+=sprintf("\n%s  %-"+(28)+"s%s",HIM+"┃"+NOR, "    根骨增加："+CHINESE_D->chinese_number(cons),HIM+"┃"+NOR);  
		}
		if(jing)
		{
			 str+=sprintf("%-"+(30)+"s%s\n","    精气加成："+CHINESE_D->chinese_number(jing),HIM+"┃"+NOR); 
		}
		if(jingli)
		{
			str+=sprintf("\n%s  %-"+(28)+"s%s\n",HIM+"┃"+NOR,"    精气加成："+CHINESE_D->chinese_number(jingli),HIM+"┃"+NOR);  
		} 
             str +=WHT"\n┣固有━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫"NOR;
str+=sprintf("%s  %-"+(28)+"s%s",WHT+"\n┃"+NOR, "    装备重量："+CHINESE_D->chinese_number(weight),WHT+"┃"+NOR);  
str+=sprintf("%-"+(30)+"s%s\n","      装备耐久："+CHINESE_D->chinese_number(lasting),WHT+"┃"+NOR); 
str+=sprintf("%s  %-"+(28)+"s%s\n",WHT+"┃"+NOR, "    装备价值: "+CHINESE_D->chinese_number(value/10000)+"两黄金",WHT+"┃"+NOR);  
		str +=HIR"┣需求━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫\n"NOR;
		if(wear_con) 
                                {
                                          str+=sprintf("%s  %-"+(28)+"s%s",HIR+"┃"+NOR,
                                                    "    根骨需求："+wear_con,HIR+"┃"+NOR);            
                                }
		else
                                { 
                                           str+=sprintf("%s  %-"+(28)+"s%s",HIR+"┃"+NOR,
                                                    "    根骨需求：无需求",HIR+"┃"+NOR);   
                                 }

		if(gender) 
                                 {
                                     gender=HIG+gender+NOR;
	                                  str+=sprintf("%-"+(30)+"s%s\n","    性别需求："+gender,HIR+"┃"+NOR);     
                                 }
		else 
                                 {
		      gender=HIG+"无需求"+NOR;
                                     str+=sprintf("%-"+(30)+"s%s\n","    性别需求："+gender,HIR+"┃"+NOR);     
		 }
                                

		if(max_neili) 
		{
                                          str+=sprintf("%s  %-"+(28)+"s%s\n",HIR+"┃"+NOR,
                                                    "    内力需求："+CHINESE_D->chinese_number(max_neili),HIR+"┃"+NOR);            
                                }
else 
                       
         {
			  str+=sprintf("%s  %-"+(28)+"s%s\n",HIR+"┃"+NOR,
                                                    "    内力需求：无需求",HIR+"┃"+NOR);    
		}

		str +=HIR"┣━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┫\n"NOR;
	
		set("long",str);
	}
	return 1;


}
return 1;

}


