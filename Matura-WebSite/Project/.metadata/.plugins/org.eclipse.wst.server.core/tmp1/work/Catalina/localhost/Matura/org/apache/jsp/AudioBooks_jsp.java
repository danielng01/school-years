/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/7.0.47
 * Generated at: 2014-04-20 16:04:26 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class AudioBooks_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final javax.servlet.jsp.JspFactory _jspxFactory =
          javax.servlet.jsp.JspFactory.getDefaultFactory();

  private static java.util.Map<java.lang.String,java.lang.Long> _jspx_dependants;

  private javax.el.ExpressionFactory _el_expressionfactory;
  private org.apache.tomcat.InstanceManager _jsp_instancemanager;

  public java.util.Map<java.lang.String,java.lang.Long> getDependants() {
    return _jspx_dependants;
  }

  public void _jspInit() {
    _el_expressionfactory = _jspxFactory.getJspApplicationContext(getServletConfig().getServletContext()).getExpressionFactory();
    _jsp_instancemanager = org.apache.jasper.runtime.InstanceManagerFactory.getInstanceManager(getServletConfig());
  }

  public void _jspDestroy() {
  }

  public void _jspService(final javax.servlet.http.HttpServletRequest request, final javax.servlet.http.HttpServletResponse response)
        throws java.io.IOException, javax.servlet.ServletException {

    final javax.servlet.jsp.PageContext pageContext;
    javax.servlet.http.HttpSession session = null;
    final javax.servlet.ServletContext application;
    final javax.servlet.ServletConfig config;
    javax.servlet.jsp.JspWriter out = null;
    final java.lang.Object page = this;
    javax.servlet.jsp.JspWriter _jspx_out = null;
    javax.servlet.jsp.PageContext _jspx_page_context = null;


    try {
      response.setContentType("text/html; charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write('\r');
      out.write('\n');
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "header.jsp", out, false);
      out.write("\r\n");
      out.write("\r\n");
      out.write("<div style=\"clear:both;padding-top: 50px;\"></div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Алеко Константинов\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Konstantinov-BaiGanioPatuva.mp3\" class=\"list-group-item\">Бай Ганьо Пътува</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Konstantinov-BaiGanioVDrezden.mp3\" class=\"list-group-item\">Бай Ганьо В Дрезден</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Konstantinov-BaiGanioVOperata.mp3\" class=\"list-group-item\">Бай Ганьо В Операта</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=konstantinov-banq.mp3\" class=\"list-group-item\">Бай Ганьо В Банята</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=konstantinov-izbori.mp3\" class=\"list-group-item\">Бай Ганьо Прави Избори</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=konstantinov-nagosti.mp3\" class=\"list-group-item\">Бай Ганьо Нагости У Иречека</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Konstantinov-RazniHoraRazniIdeali-01.mp3\" class=\"list-group-item\">Разни хора, разни идеали 1</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Konstantinov-RazniHoraRazniIdeali-02.mp3\" class=\"list-group-item\">Разни хора, разни идеали 2</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Konstantinov-RazniHoraRazniIdeali-03.mp3\" class=\"list-group-item\">Разни хора, разни идеали 3</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Konstantinov-RazniHoraRazniIdeali-04.mp3\" class=\"list-group-item\">Разни хора, разни идеали 4</a>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Атанас Далчев\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Bolnitsa\"  class=\"list-group-item list-group-item-danger\" disabled>Болница</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Dyavolsko\" class=\"list-group-item list-group-item-danger\">Дяволско</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Kamak\"     class=\"list-group-item list-group-item-danger\">Камък</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Knigite\"   class=\"list-group-item list-group-item-danger\">Книгите</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Kashtata\"  class=\"list-group-item list-group-item-danger\">Къщата</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Povest\"    class=\"list-group-item list-group-item-danger\">Повест</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Prozorets\" class=\"list-group-item list-group-item-danger\">Прозорец</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Stayata\"   class=\"list-group-item list-group-item-danger\">Стаята</a>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Гео Милев\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Septemvri\" class=\"list-group-item list-group-item-danger\">Септември</a>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Димитър Димов\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Tyutyun\" class=\"list-group-item list-group-item-danger\">Тютюн</a>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Димитър Талев\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Zhelezniyat Svetilnik\" class=\"list-group-item list-group-item-danger\">Железният Светилник</a>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Димчо Дебелянов\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Debelianov-DaSeZavarnesh.mp3\" class=\"list-group-item\">Да се завърнеш...</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Debelianov-EdinUbit.mp3\" class=\"list-group-item\">Един Убит</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Mig\" class=\"list-group-item list-group-item-danger\">Миг</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Debelianov-Polivdiv.mp3\" class=\"list-group-item\">Пловдив</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Debelianov-PomnishLi.mp3\" class=\"list-group-item\">Помниш ли, помниш ли</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Debelianov-SirotnaPesen.mp3\" class=\"list-group-item\">Сиротна песен</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Debelianov-SpiGradat.mp3\" class=\"list-group-item\">Спи Градът</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Debelianov-TihaPobeda.mp3\" class=\"list-group-item\">Тиха Победа</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Debelianov-ChernaPesen.mp3\" class=\"list-group-item\">Черна песен</a>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Елин Пелин\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Andreshko\" class=\"list-group-item list-group-item-danger\">Андрешко</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Vetrenata Melnica\" class=\"list-group-item list-group-item-danger\">Ветрената Мелница</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Geracite\" class=\"list-group-item list-group-item-danger\">Гераците</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Zadushnica\" class=\"list-group-item list-group-item-danger\">Задушница</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Zanemelite kambani\" class=\"list-group-item list-group-item-danger\">Занемелите камбани</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Kosachi\" class=\"list-group-item list-group-item-danger\">Косачи</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Mechtateli\" class=\"list-group-item list-group-item-danger\">Мечтатели</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Na onya svyat\" class=\"list-group-item list-group-item-danger\">На оня свят</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Chorba ot grexovete na otec Nikodim\" class=\"list-group-item list-group-item-danger\">Чорба от греховете на отец Никодим</a>\r\n");
      out.write("  \r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Елисавета Багряна\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Vechnata\" class=\"list-group-item list-group-item-danger\">Вечната</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Kukuvica\" class=\"list-group-item list-group-item-danger\">Кукувица</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=ElisavetaBagriana-Potomka.mp3\" class=\"list-group-item\">Потомка</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Stihii\" class=\"list-group-item list-group-item-danger\">Стихии</a>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Иван Вазов\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Vazov-BalgarskiatEzik.mp3\" class=\"list-group-item\">Българският език</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Dyado Yotso gleda\" class=\"list-group-item list-group-item-danger\">Дядо Йоцо гледа</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Elate ni vizhte\" class=\"list-group-item list-group-item-danger\">Елате ни вижте</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Vazov-Kocho.mp3\" class=\"list-group-item\">Кочо</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Vazov-Levski.mp3\" class=\"list-group-item\">Левски</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Linee nashto pokolenye\" class=\"list-group-item list-group-item-danger\">Линее нашто поколенье</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Vazov-OpalchentsiteNaShipka.mp3\" class=\"list-group-item\">Опълченците на Шипка</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Otechestvo lyubezno\" class=\"list-group-item list-group-item-danger\">Отечество любезно</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Vazov-Paisii.mp3\" class=\"list-group-item\">Паисий</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Pod igoto\" class=\"list-group-item list-group-item-danger\">Под игото</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Pri Rilskiya manastir\" class=\"list-group-item list-group-item-danger\">При Рилския манастир</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Chichovtsi\" class=\"list-group-item list-group-item-danger\">Чичовци</a>\r\n");
      out.write("</div>     \r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Йордан Йовков\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Albena\" class=\"list-group-item list-group-item-danger\">Албена</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Drugoselets\" class=\"list-group-item list-group-item-danger\">Другоселец</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Inzhde\" class=\"list-group-item list-group-item-danger\">Инжде</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Pesenta na koleletata\" class=\"list-group-item list-group-item-danger\">Песента на колелетата</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Posledna radost\" class=\"list-group-item list-group-item-danger\">Последна радост</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Prez chumavoto\" class=\"list-group-item list-group-item-danger\">През чумавото</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Serafim\" class=\"list-group-item list-group-item-danger\">Серафим</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Shibil\" class=\"list-group-item list-group-item-danger\">Шибил</a>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Никола Вапцаров\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Vaptsarov-BorbataEBezmilostnoJestoka.mp3\" class=\"list-group-item\">Борбата е безмилостно жестока</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Vyara\" class=\"list-group-item list-group-item-danger\">Вяра</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Zavod\" class=\"list-group-item list-group-item-danger\">Завод</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Istoriya\" class=\"list-group-item list-group-item-danger\">История</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Kino\" class=\"list-group-item list-group-item-danger\">Кино</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Pesen za choveka\" class=\"list-group-item list-group-item-danger\">Песен за човека</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Pismo\" class=\"list-group-item list-group-item-danger\">Писмо</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Vaptsarov-Proshtalno.mp3\" class=\"list-group-item\">Прощално</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=San\" class=\"list-group-item list-group-item-danger\">Сън</a>\r\n");
      out.write("  \r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Пейо Яворов\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Iavorov-Gradushka.mp3\" class=\"list-group-item\">Градушка</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Dve dushi\" class=\"list-group-item list-group-item-danger\">Две души</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Dve hubavi ochi\" class=\"list-group-item list-group-item-danger\">Две хубави очи</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Iavorov-Zatochenici.mp3\" class=\"list-group-item\">Заточеници</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Maska\" class=\"list-group-item list-group-item-danger\">Маска</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Pesenta na choveka\" class=\"list-group-item list-group-item-danger\">Песента на човека</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Senki\" class=\"list-group-item list-group-item-danger\">Сенки</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Ston\" class=\"list-group-item list-group-item-danger\">Стон</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Shte badesh v byalo\" class=\"list-group-item list-group-item-danger\">Ще бъдеш в бяло</a>\r\n");
      out.write("        \r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Пенчо Славейков\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Cis moll\" class=\"list-group-item list-group-item-danger\">Cis moll</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Ni lah ne dahva nad poleni\" class=\"list-group-item list-group-item-danger\">Ни лъх не дъхва над полени</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Ralitsa\" class=\"list-group-item list-group-item-danger\">Ралица</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Samoten grob v samoten kat\" class=\"list-group-item list-group-item-danger\">Самотен гроб в самотен кът</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Spi ezeroto\" class=\"list-group-item list-group-item-danger\">Спи езерото</a>\r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Христо Ботев\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Borba\" class=\"list-group-item list-group-item-danger\">Борба</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Do moeto parvo libe\" class=\"list-group-item list-group-item-danger\">До моето първо либе</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Botev-Elegiq.mp3\" class=\"list-group-item\">Елегия</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Botev-kamBrataSi.mp3\" class=\"list-group-item\">Към брата си</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Botev-MaitseSi.mp3\" class=\"list-group-item\">Майце си</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Botev-MoqtaMolitva.mp3\" class=\"list-group-item\">Моята молитва</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Botev-NaProshtavane.mp3\" class=\"list-group-item\">На прощаване 1868г.</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Botev-obesvanetoNaVasilLevski.mp3\" class=\"list-group-item\">Обесването на Васил Левски</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Botev-HadjiDimitar.mp3\" class=\"list-group-item\">Хаджи Димитър</a>\r\n");
      out.write("  \r\n");
      out.write("</div>\r\n");
      out.write("<div class=\"list-group\">\r\n");
      out.write("  <a href=\"#\" class=\"list-group-item active\">\r\n");
      out.write("    Христо Смирненски\r\n");
      out.write("  </a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Smirnenski-DaBadeDen.mp3\" class=\"list-group-item\">Да бъде ден</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Zimni vecheri\" class=\"list-group-item list-group-item-danger\">Зимни вечери</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Yohan\" class=\"list-group-item list-group-item-danger\">Йохан</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Niy\" class=\"list-group-item list-group-item-danger\">Ний</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Stariya muzikant\" class=\"list-group-item list-group-item-danger\">Стария музикант</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Tsvetarka\" class=\"list-group-item list-group-item-danger\">Цветарка</a>\r\n");
      out.write("  <a href=\"GetAudioBook.jsp?proizvedenie=Yunosha\" class=\"list-group-item list-group-item-danger\">Юноша</a>\r\n");
      out.write("</div>\r\n");
      out.write("\r\n");
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "footer.jsp", out, false);
      out.write(' ');
    } catch (java.lang.Throwable t) {
      if (!(t instanceof javax.servlet.jsp.SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          try { out.clearBuffer(); } catch (java.io.IOException e) {}
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}