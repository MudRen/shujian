//edit by rock,�޸� by hongba
//2008.10.15

string check_len(string str)
{
	int max_len = 33,len;
	
	len = strlen(str);
	return sprintf("%"+len+"s","��\n");
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
			case 1  : equip_zl = HIG"�м�"NOR; break;
			case 2  : equip_zl = CYN"�߼�"NOR; break;
			case 3  : equip_zl = HIR"׿Խ"NOR; break;
			default : equip_zl = WHT"����"NOR; break;
		}
		
		chars =HIY+"("+equip_zl+")"+NOR;
		
                                  if(zj) temp_str = zj+name+chars;
                                  else temp_str = name+chars;
		   str=YEL"����������"NOR+temp_str+YEL"����������\n"NOR;;
         str += sprintf(NOR YEL"�ǩ������������������������������ש�������������������������������\n"NOR);
                            		  
                                str+=sprintf("%s  %-"+(28)+"s%s\n",YEL+"��"+NOR,
                                                    "    װ��������"+CHINESE_D->chinese_number(armor)+"( "+ CHINESE_D->chinese_numbe(dp) +" )",YEL+"��"+NOR);         
                                str +=HIM"�Ǹ��ө��������������������������贈������������������������������\n"NOR;   
		if(hp)
		{
			  str+=  sprintf("%s  %-"+(28)+"s%s",HIM+"��"+NOR,"    ��Ѫ�ӳɣ�"+CHINESE_D->chinese_number(hp),HIM+"��"+NOR);      
		}
		if(mp)
		{
			 str+=sprintf("%-"+(30)+"s%s\n","    �����ӳɣ�"+CHINESE_D->chinese_number(mp),HIM+"��"+NOR); 	
		}

		if(pp)
		{
			  str+=sprintf("\n%s  %-"+(28)+"s%s",HIM+"��"+NOR, "    ׷�ӷ�����"+CHINESE_D->chinese_number(pp),HIM+"��"+NOR);      
		}

		if(cp)
		{
			 str+=sprintf("%-"+(30)+"s%s\n","    ��ǿ������"+CHINESE_D->chinese_number(cp),HIM+"��"+NOR); 
		}

		if(ap)
		{
			 str+=sprintf("\n%s  %-"+(28)+"s%s",HIM+"��"+NOR, "    ׷�ӹ�����"+CHINESE_D->chinese_number(ap),HIM+"��"+NOR);      
		}
		if(strs)
		{
			 str+=sprintf("%-"+(30)+"s%s\n","    �������ӣ�"+CHINESE_D->chinese_number(strs),HIM+"��"+NOR); 
		}
		if(dex)
		{
			 str+=sprintf("\n%s  %-"+(28)+"s%s",HIM+"��"+NOR, "    �����ӣ�"+CHINESE_D->chinese_number(dex),HIM+"��"+NOR);      
		}
		if(ints)
		{
			 str+=sprintf("%-"+(30)+"s%s\n","    �������ӣ�"+CHINESE_D->chinese_number(ints),HIM+"��"+NOR); 
		}
		if(cons)
		{
			str+=sprintf("\n%s  %-"+(28)+"s%s",HIM+"��"+NOR, "    �������ӣ�"+CHINESE_D->chinese_number(cons),HIM+"��"+NOR);  
		}
		if(jing)
		{
			 str+=sprintf("%-"+(30)+"s%s\n","    �����ӳɣ�"+CHINESE_D->chinese_number(jing),HIM+"��"+NOR); 
		}
		if(jingli)
		{
			str+=sprintf("\n%s  %-"+(28)+"s%s\n",HIM+"��"+NOR,"    �����ӳɣ�"+CHINESE_D->chinese_number(jingli),HIM+"��"+NOR);  
		} 
             str +=WHT"\n�ǹ��Щ��������������������������贈������������������������������"NOR;
str+=sprintf("%s  %-"+(28)+"s%s",WHT+"\n��"+NOR, "    װ��������"+CHINESE_D->chinese_number(weight),WHT+"��"+NOR);  
str+=sprintf("%-"+(30)+"s%s\n","      װ���;ã�"+CHINESE_D->chinese_number(lasting),WHT+"��"+NOR); 
str+=sprintf("%s  %-"+(28)+"s%s\n",WHT+"��"+NOR, "    װ����ֵ: "+CHINESE_D->chinese_number(value/10000)+"���ƽ�",WHT+"��"+NOR);  
		str +=HIR"�����󩥩������������������������贈������������������������������\n"NOR;
		if(exp) 
                                {
                                          str+=sprintf("%s  %-"+(28)+"s%s",HIR+"��"+NOR,
                                                    "    ��������"+exp,HIR+"��"+NOR);            
                                }
		else
                                { 
                                           str+=sprintf("%s  %-"+(28)+"s%s",HIR+"��"+NOR,
                                                    "    ��������������",HIR+"��"+NOR);   
                                 }

		if(gender) 
                                 {
                                     gender=HIG+gender+NOR;
	                     str+=sprintf("%-"+(30)+"s%s\n","    �Ա�����"+gender,HIR+"��"+NOR);     
                                 }
		else 
                                 {
		      gender=HIG+"������"+NOR;
                                     str+=sprintf("%-"+(30)+"s%s\n","    �Ա�����"+gender,HIR+"��"+NOR);     
		 }
                                
/*
		if(level) 
		{
                                          str+=sprintf("%s  %-"+(28)+"s%s\n",HIR+"��"+NOR,
                                                    "    �ȼ�����"+CHINESE_D->chinese_number(level),HIR+"��"+NOR);            
                                }
else 
                       
         {
			  str+=sprintf("%s  %-"+(28)+"s%s\n",HIR+"��"+NOR,
                                                    "    �ȼ�����������",HIR+"��"+NOR);    
		}
*/
		str +=HIR"�ǩ������������������������������ߩ�������������������������������\n"NOR;
	
		ob->set("long",str);
	}
	return 1;
}