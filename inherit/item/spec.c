// spec.c

inherit ITEM;

int restrict()
{
	string this_flag = this_object()->query("flag");
	int this_week=time()/86400/7;
	
	if (this_player()->query("spec/last_week")!=this_week)
		{this_player()->delete("spec");this_player()->set("spec/last_week",this_week);}
	
	if (!query("rest")) return 1;
	 
	if (this_player()->query(this_flag)+1>query("rest"))
       		return 0;	 
	else
		return 1;
}

void degree()
{
        string this_flag = query("flag");
	
	this_player()->add(this_flag,1);
	write("�������Ѿ�ʹ��"+query("name")+chinese_number(this_player()->query(this_flag))+"�Ρ�\n");
        if (add("degree",-1)<1) 
        	{write("���"+query("name")+"�Ѿ�������!\n");destruct(this_object());}
	else
		{write("���"+query("name")+"����ʹ��"+chinese_number(query("degree"))+"��!\n");}
}
