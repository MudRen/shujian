string s_power(int i)
{
	if( i >= 18 )	return HIW"����"NOR;
	if( i >= 14 )	return HIG"�ܸ�"NOR;	
	if( i >= 7 )	return HIY"����"NOR;		
	return "һ��";
}

void token_reload()
{
	string str;
	int i;
	if(mapp(this_player()->query("token/"+query("id"))))
	{			
		if (i=this_player()->query("token/"+query("id")+"/parry")) 
		{
			set("armor_prop/parry",i);
			str="������";
		}	
		if (i=this_player()->query("token/"+query("id")+"/dodge"))
		{
			set("armor_prop/dodge",i);
			str="�����";
		}
		set("long",query("long")+" "+this_player()->query("token/"+query("id")+"/desc")+"\n"NOR
			+"\n���"+query("name")+"����������"+s_power(i)+"��"+str+"��\n");
		wear();
	}
}

int do_discard(string arg)
{
	object me = this_player();
	if (arg!=query("id"))
      		return notify_fail("��Ҫ����ʲô?\n");
      	
      	write("��Ҫ����"+query("name")+",ȷ����[Y|N]��");
	input_to("confirm_discard",me);
      	return 1;
}

private void confirm_discard(string arg,object me)
{
	if( arg[0]=='y' || arg[0]=='Y' )
	{
		me->delete("token/"+query("id"));
		write("��ж��"+query("name")+"����ض���û��ע��Ľ��䡣\n");
		destruct(this_object());
	}
	else
	{
		write("\n���������"+ query("name")+"��\n");
	}
}

int query_autoload()
{
	return 1;
}

int unequip()
{
	object ob = environment();

	if (ob && userp(ob))
		return notify_fail("������������Ͱ�������(discard)�˰ɡ�\n");

	return ::unequip();
}