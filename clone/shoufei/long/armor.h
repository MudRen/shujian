//edit by rock,修改 by hongba
//2008.10.15

string check_len(string str)
{
	int max_len = 33,len;
	
	len = strlen(str);
	return sprintf("%"+len+"s","│\n");
}

int init()
{
	object ob = this_object();
	string name,gender,str,temp_str,equip_zl,chars;
	int weight,level,value,armor,ap,dp,pp,hp,mp,exp,lasting,cp,zl,zj,strs,dex,ints,cons,jing,jingli;

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
		exp = ob->query("exp");
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

		switch(zl)
		{
			case 1  : equip_zl = HIG"中级"NOR; break;
			case 2  : equip_zl = CYN"高级"NOR; break;
			case 3  : equip_zl = HIR"卓越"NOR; break;
			default : equip_zl = WHT"初级"NOR; break;
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
			 str+=sprintf("%-"+(30)+"s%s\n","    臂力增加："+CHINESE_D->chinese_number(strs),HIM+"┃"+NOR); 
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
		if(exp) 
                                {
                                          str+=sprintf("%s  %-"+(28)+"s%s",HIR+"┃"+NOR,
                                                    "    经验需求："+exp,HIR+"┃"+NOR);            
                                }
		else
                                { 
                                           str+=sprintf("%s  %-"+(28)+"s%s",HIR+"┃"+NOR,
                                                    "    经验需求：无需求",HIR+"┃"+NOR);   
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
                                
/*
		if(level) 
		{
                                          str+=sprintf("%s  %-"+(28)+"s%s\n",HIR+"┃"+NOR,
                                                    "    等级需求："+CHINESE_D->chinese_number(level),HIR+"┃"+NOR);            
                                }
else 
                       
         {
			  str+=sprintf("%s  %-"+(28)+"s%s\n",HIR+"┃"+NOR,
                                                    "    等级需求：无需求",HIR+"┃"+NOR);    
		}
*/
		str +=HIR"┣━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┫\n"NOR;
	
		ob->set("long",str);
	}
	return 1;
}