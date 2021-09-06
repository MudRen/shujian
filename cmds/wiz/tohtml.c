// /u/look/workroom.c include Exp sort and online player
// And write to /log/html/top10.html. Link to /home/httpd/html/top10.html
// And write to /log/html/onlineuser.html. Link to /home/httpd/html/onlineuser.html
// And write to /log/html/party.html. Link to /home/httpd/html/party.html
// And write to /log/html/count24.html. Link to /home/httpd/html/count24.html
// Write By Look@SJ 19990906
// Modify by LinuX@SJ 2004-4-1

inherit F_DBASE;

#include <database.h>
#include <ansi.h>
#include <mudlib.h>
#include <localtime.h>

int sort_user(object,object);
int sort(object obj1, object obj2);
int filldata(object obj1);
int writefile();
string remove_ansi(string str);

nosave object* list;
nosave int now_num;
nosave int user_num;
nosave int count_user;
nosave string fnameb;
nosave string fnamea;
nosave int ppl_cnt;

void create()
{
	seteuid(getuid());
	set("channel_id", "���;���");
}

int main(object me, string arg)
{
	CHANNEL_D->do_channel( this_object(), "sys","����������ݸ��µ�WEB������");
	remove_call_out("writefile");
	call_out("writefile", 0);
        return 1;

}

int clean_up()
{
    return 0;
}

int writefile()
{
        int totalexp = 0, max, i, j = 1;
        string show="",fname="";
        mixed *ob_list, *ob_list_old;
        object *ob, obj1;
        string top10 = "";
        string onlineuser = "";
        string party = "";
        string title="";
                
        ob_list_old = users();
        ob_list_old = filter_array(ob_list_old, (: filldata :));
        max=sizeof(ob_list_old);
        if (max > 10) max=10;
        ob_list = sort_array(ob_list_old, (: sort :));
        top10 += "<table width='97%' border='0' align='center' bgcolor='#000000'>
  <tr>
    <td height='317'><div align='center'><BR>
        <strong><font color='#FFFF00' face='Fixedsys'>" + CHINESE_MUD_NAME + "����ʮ�����("+CHINESE_D->chinese_date(time(),1)+")</font></strong><font face='Fixedsys'><br>
        </font></div>
      <table width='70%' border='0' align='center' cellpadding='4' cellspacing='3' bgcolor='#000000'>
        <tr align=center> 
          <td width='10%' height='30'><font color='#00FF00' face='Fixedsys'><strong>���� 
            </strong></font></td>
          <td width='50%' height='30'><font color='#00FF00' face='Fixedsys'><strong>�ǳ�</strong></font></td>
          <td width='25%' height='30'><font color='#00FF00' face='Fixedsys'><strong> 
            ����</strong></font></td>
          <td width='15%' height='30'><font color='#00FF00' face='Fixedsys'><strong>����</strong></font></td>
        </tr>";
        for (i=0;i<max;i++)
          {
            obj1 = ob_list[i];
            show = obj1->query("name")+"("+capitalize(obj1->query("id"))+")";
            top10 += sprintf("<tr align=center> 
          <td><font color='#008000' face='Fixedsys'>No.%d</font></td>
          <td><font color='#008000' face='Fixedsys'>��%s��</font></td>
          <td><font color='#008000' face='Fixedsys'>%s</font></td>
          <td><font color='#008000' face='Fixedsys'>%s</font></td>
          </tr>",
          i+1,obj1->query("nickname")?obj1->query("nickname"):"����",show,
          obj1->query("family/family_name"));
          }
        top10 += "</table>
      <br>
    </td>
  </tr>
</table>";
 
//������Ҽ�����ʵ���ļ�����
        onlineuser += "<table width='97%' border='0' align='center' bgcolor='#000000'>
  <tr>
    <td height='317'><div align='center'><BR>
        <strong><font color='#FFFF00' face='Fixedsys'>" + CHINESE_MUD_NAME + "��������嵥("+CHINESE_D->chinese_date(time(),1)+")</font></strong><font face='Fixedsys'><br>
        </font></div>
      <table border=0 cellpadding=0 cellspacing=5 width='97%'>
        <tr align=center> 
          <td width='12%' ><font color='#FFFF00' face='Fixedsys'>����</font></td>
          <td colspan=4 ><font color='#FFFF00' face='Fixedsys'>��������(ID)</font></td>
        </tr>";

	party += "<table width='97%' border='0' align='center' bgcolor='#000000'>
  <tr>
    <td height='317'><div align='center'><BR>
        <strong><font color='#FFFF00' face='Fixedsys'>" + CHINESE_MUD_NAME + "�����������ʵ��ͼʾ("+CHINESE_D->chinese_date(time(),1)+")</font></strong><font face='Fixedsys'><br>
        </font></div>
      <table border=0 cellpadding=0 cellspacing=0 width='97%'>
        <tr align=center> 
          <td width='12%'><font color='#00FF00' face='Fixedsys'>����</font></td>
          <td width='88%'><font color='#00FF00' face='Fixedsys'>�ۺ�ʵ��</font></td>
        </tr>";

        ob = filter_array(objects(), (: userp :));
        list = sort_array(ob, (: sort_user :));
        ppl_cnt = 0;
        i = sizeof(list);
        while( i-- ) {
                if( !environment(list[i]) ) continue;
                if (wizardp(list[i]) && list[i]->query("env/invisibility")) continue;
                if (!wiz_level(list[i]) && fname != list[i]->query("family/family_name")) {
                  if (totalexp > 7000000) totalexp = 7000000;
		    if ((fname?totalexp:0) != 0)
		    {
		    	party += sprintf("%s%d%s\n","        <tr> 
          <td align=center><font color='#008000' face='Fixedsys'>"+fname+"</font></td>
          <td><hr align=left noshade size='10' color='#FF0000' width='",(totalexp/70000),"%'>");
		    	party += sprintf("%s%d%s\n",
		    	"<hr align=left noshade size='10' color='#0000FF' width='",(totalexp/70000)/j,"%'></td></tr>");
		    }
                    fname = list[i]->query("family/family_name");
                    
                    totalexp = 1;
                    j = 0;
                }
                if (!wiz_level(list[i])){
                	totalexp += (int)list[i]->query("combat_exp");
                	j ++;
                }
                if (interactive(list[i])) ppl_cnt++;
        }
   	party += sprintf("%s%d%s\n","<tr> 
          <td align=center><font color='#008000' face='Fixedsys'>"+fname+"</font></td>
          <td><hr align=left noshade size='10' color='#FF0000' width='",(totalexp/70000),"%'>");
   	party += sprintf("%s%d%s\n","<hr align=left noshade size='10' color='#0000FF' width='",(totalexp/70000)/j,"%'></td></tr>");
        party += "</table>
      <div align='center'> 
        <p><font color=#FF0000 face='Fixedsys'>��ɫ</font><font color=#008000 face='Fixedsys'>��ʾ����EXP�ܺͣ�<font color='#0000FF'>��ɫ</font>��ʾEXPƽ��ֵ��</font><br>
        </p>
      </div></td>
  </tr>
</table>";
       
        title += "<table width='97%' border='0' align='center' bgcolor='#000000'>
  <tr>
    <td height='317'><div align='center'><BR>
        <strong><font color='#FFFF00' face='Fixedsys'>" + CHINESE_MUD_NAME + "���������ϸ����("+CHINESE_D->chinese_date(time(),1)+")</font></strong><font face='Fixedsys'><br>
        </font></div>
      <table border=0 cellpadding=0 cellspacing=5 width='97%'>
        <tr align=left> 
          <td width='12%' ><font color='#FFFF00' face='Fixedsys'>����</font></td>          
        </tr>";
        
	top10 = replace_string(top10,"'","\"");
	onlineuser = replace_string(onlineuser,"'","\"");
	party = replace_string(party,"'","\"");	
	title = replace_string(title,"'","\"");
//�ļ����ɽ���
	now_num = 0;
	fnamea ="";
	if (BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "REPLACE INTO mud_info (subject, utime, content, type, site)
			VALUES ('"+CHINESE_MUD_NAME+"���������ϸ����"+"', '"+time()+"', 
			'"+title+"', 'title', '"+lower_case(INTERMUD_MUD_NAME)+"')",this_object(),"upload_title"))
				CHANNEL_D->do_channel( this_object(), "sys", "���������ϸ�����Զ����µ���ҳ.........��ʼ����...��");
			else
				CHANNEL_D->do_channel( this_object(), "sys", "���������ϸ�����Զ����µ���ҳ.........ʧ�ܡ�");
				
	if (BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "REPLACE INTO mud_info (subject, utime, content, type, site)
			VALUES ('"+CHINESE_MUD_NAME+"����ʮ�����"+"', '"+time()+"', 
			'"+top10+"', 'top', '"+lower_case(INTERMUD_MUD_NAME)+"')"))
				CHANNEL_D->do_channel( this_object(), "sys", "����ʮ����������Զ����µ���ҳ.........�ɹ���");
			else
				CHANNEL_D->do_channel( this_object(), "sys", "����ʮ����������Զ����µ���ҳ.........ʧ�ܡ�");

	user_num = 0;
	count_user =0;
	fnameb ="";
	if (BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "REPLACE INTO mud_info (subject, utime, content, type, site)
			VALUES ('"+CHINESE_MUD_NAME+"�������"+"', '"+time()+"', 
			'"+onlineuser+"', 'online', '"+lower_case(INTERMUD_MUD_NAME)+"')",this_object(),"upload_user"))
				CHANNEL_D->do_channel( this_object(), "sys", "������������Զ����µ���ҳ.........��ʼ����...��");
			else
				CHANNEL_D->do_channel( this_object(), "sys", "������������Զ����µ���ҳ.........ʧ�ܡ�");
	
	if (BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "REPLACE INTO mud_info (subject, utime, content, type, site)
			VALUES ('"+CHINESE_MUD_NAME+"�����������ʵ��ͼʾ"+"', '"+time()+"', 
			'"+party+"', 'party', '"+lower_case(INTERMUD_MUD_NAME)+"')"))			
				CHANNEL_D->do_channel( this_object(), "sys", "�����������ʵ��ͼʾ�����Զ����µ���ҳ.........�ɹ���");
			else
				CHANNEL_D->do_channel( this_object(), "sys", "�����������ʵ��ͼʾ�����Զ����µ���ҳ.........ʧ�ܡ�");
				
	remove_call_out("writefile");
	call_out("writefile", 3600);
	return 1;
}
string get_frame(object ob);

void upload_title(mixed ret)
{	
	int i = 0;
	string title ="";
	string sql;
	int max = now_num+10;
	if(max>sizeof(list)) max=sizeof(list);
	for(i=now_num+0;i<max;i++){
		if(!objectp(list[i])) continue;
		if( !environment(list[i]) ) continue;
                if (wizardp(list[i]) && list[i]->query("env/invisibility")) continue;
                if(fnamea!=get_frame(list[i]))
                {
                	fnamea=get_frame(list[i]);
          	    	title += "<td width='12%' align=left ><font color='#00FF00' face='Fixedsys'>"+fnamea+ "</font></td>";
          	    	title += "</tr><tr> ";
                }
                     
		title += sprintf("%s%12s%s%s%s\n",
			"<td width='22%'><font color='#008000' face='Fixedsys'>",
			RANK_D->query_rank(list[i]),
			interactive(list[i])?
			(query_idle(list[i]) > 120?HIM"+"NOR:" ")
			:HIG"*"NOR,
			list[i]->short(1),
			"</font></td>"
		);
		title += "</tr><tr> ";
	}
	title = replace_string(title,"'","\"");
	now_num += 10;	
	if(title!="") 
	{
	sql = sprintf("UPDATE mud_info SET content = CONCAT(content,'%s') WHERE subject='%s' AND site = '%s'",
	title,CHINESE_MUD_NAME+"���������ϸ����",lower_case(INTERMUD_MUD_NAME));
	BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,sql,this_object(),"upload_title");	
	//message("wizard", sql,users());
	CHANNEL_D->do_channel( this_object(), "sys", "���������ϸ�����Զ����µ���ҳ.........��������...��");
	}
	else
	{
		title = "</table>
      			<div align='center'>
        		<p><font color='#008000' face='Fixedsys'>\n";
        	title += sprintf("�� <font color=yellow>%d</font> λ��������С�</font></p>
        			<p><br>
        			</p>
      				</div></td>
  				</tr>
				</table>", ppl_cnt);
		title = replace_string(title,"'","\"");
		sql = sprintf("UPDATE mud_info SET content = CONCAT(content,'%s') WHERE subject='%s' AND site = '%s'",
		title,CHINESE_MUD_NAME+"���������ϸ����",lower_case(INTERMUD_MUD_NAME));
		BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,sql);	
		CHANNEL_D->do_channel( this_object(), "sys", "���������ϸ�����Զ����µ���ҳ.........�ɹ���");
	}
}
void upload_user(mixed ret)
{
	int i = 0;
	string str="";
	string sql;	
	int max = user_num+100;
	if(max>sizeof(list)) max=sizeof(list);	
	for(i=user_num+0;i<max;i++){
		if(!objectp(list[i])) continue;
		if( !environment(list[i]) ) continue;
                if (wizardp(list[i]) && list[i]->query("env/invisibility")) continue;
                if(fnameb!=get_frame(list[i]))
                {
                	fnameb=get_frame(list[i]);
                	if (count_user % 5) str += "</tr><tr> ";
          	    	str += "<td width='12%' align=center ><font color='#00FF00' face='Fixedsys'>"+fnameb+ "</font></td>";
                    	count_user = 1;
                }
		if (!(count_user % 5)) {
                	count_user++;
                  	str += "<td>��</td>";
                }
                str += sprintf("%s%s%s",
                      "<td width='22%'><font color='#008000' face='Fixedsys'>"+
                      (interactive(list[i])?(query_idle(list[i]) > 120?"<font color=BLUE>":""):"<font color=RED>"),
                      list[i]->name(1) + "("+capitalize(list[i]->query("id"))+")"+(interactive(list[i])?"":"</font>")+"</td>",
                      (++count_user % 5) ? "" : "</tr>\n<tr>");
	}
	str = replace_string(str,"'","\"");
	user_num += 100;
	if(str!="") 
	{
	sql = sprintf("UPDATE mud_info SET content = CONCAT(content,'%s') WHERE subject='%s' AND site = '%s'",
	str,CHINESE_MUD_NAME+"�������",lower_case(INTERMUD_MUD_NAME));
	BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,sql,this_object(),"upload_user");
	CHANNEL_D->do_channel( this_object(), "sys", "������������Զ����µ���ҳ.........��������...��");
	//message("wizard", sql,users());
	}
	else {
		str = "</table>
      			<div align='center'>
        		<p><font color='#008000' face='Fixedsys'>\n";
        	str += sprintf("�� <font color=yellow>%d</font> λ��������У�<font color='#FF0000'>��ɫ</font>��ʾ���ߣ�<font color=BLUE>��ɫ</font>��ʾ������</font></p>
        			<p><br>
        			</p>
      				</div></td>
  				</tr>
				</table>", ppl_cnt);
		str = replace_string(str,"'","\"");
		sql = sprintf("UPDATE mud_info SET content = CONCAT(content,'%s') WHERE subject='%s' AND site = '%s'",
		str,CHINESE_MUD_NAME+"�������",lower_case(INTERMUD_MUD_NAME));
		BBS_D->add_Bbs_Up_Map(WEB_DB_NAME,sql);
		CHANNEL_D->do_channel( this_object(), "sys", "������������Զ����µ���ҳ.........�ɹ���");
	}
}
string get_frame(object ob)
{
	if(wiz_level(ob)) return "��Ϸ����Ա";
	if(!mapp(ob->query("family"))) return "��ͨ����";
	return ob->query("family/family_name");	
}

int sort(object obj1, object obj2)
{
  int temp1,temp2;
  temp1=obj1->query("combat_exp");
  temp2=obj2->query("combat_exp");
  if (temp1>temp2) return -1;
  else if (temp1<temp2) return 1;
  else return 0;
}

int filldata(object obj1)
{
  if(wiz_level(obj1)) return 0;
  if(!environment(obj1)) return 0;
  else return 1;
}

string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                           HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                           HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                           BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                           NOR, BOLD });
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
                }
        return str;
}

int sort_user(object ob1, object ob2)
{
        string name1, name2;

        reset_eval_cost();
        if( wiz_level(ob1) != wiz_level(ob2) )
                return wiz_level(ob1)- wiz_level(ob2);

        name1 = get_frame(ob1);
        name2 = get_frame(ob2);
        //name1 = ob1->query("family/family_name");
        //name2 = ob2->query("family/family_name");
        
        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        name1 = ob1->query("id");
        name2 = ob2->query("id");

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;
//      return 0;
	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
